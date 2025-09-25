# _D3DDDICB_ESCAPE structure

## Description

The D3DDDICB_ESCAPE structure describes information that a user-mode display driver shares with a display miniport driver.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) that was originally passed to the user-mode display driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) or [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function or **NULL**, if the shared information is not associated with a display device.

### `Flags` [in]

A [D3DDDI_ESCAPEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags) structure that indicates, in bit-field flags, how to share information. The user-mode display driver should specify the **HardwareAccess** bit-field flag to indicate that the display miniport driver must access graphics hardware in such a way that the operating system must perform the [second level of synchronization](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level) into the display miniport driver for the [DxgkDdiEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) call.

### `pPrivateDriverData` [in/out]

A pointer to a buffer that is allocated by the user-mode display driver that contains information that the user-mode display driver sends to the display miniport driver or that the user-mode display driver receives from the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

### `hContext` [in]

A handle to the context that the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function returned or **NULL**, if the shared information is not associated with a context. If the user-mode display driver sets **hContext** to a non-**NULL** value, the driver must have also set **hDevice** to a non-**NULL** value, and **hDevice** must correspond to the device that owns the context.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))

[pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)