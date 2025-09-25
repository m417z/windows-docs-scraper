# IPrintOemUni::DriverDMS

## Description

The `IPrintOemUni::DriverDMS` method allows a rendering plug-in for [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/) to indicate that it uses a device-managed drawing surface.

## Parameters

### `pDevObj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pBuffer`

Caller-supplied pointer to a buffer to receive method-specified flags. (See the following Remarks section.)

### `cbSize`

Caller-supplied size, in bytes, of the buffer pointed to by *pBuffer*.

### `pcbNeeded`

Caller-supplied pointer to a location to receive the required minimum *pBuffer* size.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |

## Remarks

A rendering plug-in for Unidrv must implement the `IPrintOemUni::DriverDMS` method. The method will be called only if Unidrv finds a valid interface pointer to the OEM's rendering plug-in.

The `IPrintOemUni::DriverDMS` method allows a rendering plug-in to indicate that it will be using a device-managed drawing surface instead of the default GDI-managed surface.

The method must specify HOOK_-prefixed flags in the buffer pointed to by *pBuffer*, indicating which of the plug-in's graphics DDI hooking functions are to be called for the drawing surface. The HOOK_-prefixed flags are defined in winddi.h and described in the [EngAssociateSurface](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engassociatesurface) function's description. Flags specified by `IPrintOemUni::DriverDMS` are passed by Unidrv to **EngAssociateSurface**. (Note that to support a device-managed surface, the rendering plug-in must hook out all drawing functions.) For more information, see [Handling Device-Managed Surfaces](https://learn.microsoft.com/windows-hardware/drivers/print/handling-device-managed-surfaces).

If `IPrintOemUni::DriverDMS` sets flags in the buffer pointed to by *pBuffer*, Unidrv creates a device-managed surface by calling [EngCreateDeviceSurface](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engcreatedevicesurface). If `IPrintOemUni::DriverDMS` does not set any flags, Unidrv creates a GDI-managed surface by calling [EngCreateBitmap](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engcreatebitmap). In either of these cases, `IPrintOemUni::DriverDMS` should return S_OK.

If the output buffer size specified by *cbSize* is too small, the method should specify the required size in the location pointed to by *pcbNeeded*, call **SetLastError**(ERROR_INSUFFICIENT_BUFFER), and return E_FAIL.