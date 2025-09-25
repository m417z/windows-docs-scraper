# PFND3DDDI_PRESENTMULTIPLANEOVERLAY callback function

## Description

Called by the Microsoft Direct3D runtime to notify the user-mode display driver that an application finished rendering and requests that the driver display the source surface by either copying or flipping or that the driver perform a color-fill operation. Must be implemented by Windows Display Driver Model (WDDM) 1.3 or later drivers that support multiplane overlays.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pPresent* [in]

A pointer to a [D3DDDIARG_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_presentmultiplaneoverlay) structure that describes how to display to the destination surface.

## Return value

If this routine succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the user-mode display driver successfully completes its processing of a call to this function, it presents the source surface to the display by calling the [pfnPresentMultiPlaneOverlayCb (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlaycb) function.

## See also

[D3DDDIARG_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_presentmultiplaneoverlay)

[pfnPresentMultiPlaneOverlayCb (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlaycb)