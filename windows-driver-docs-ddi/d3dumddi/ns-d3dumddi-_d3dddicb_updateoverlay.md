# _D3DDDICB_UPDATEOVERLAY structure

## Description

The D3DDDICB_UPDATEOVERLAY structure describes parameters for modifying an overlay.

## Members

### `hKernelOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the [pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb) function and that identifies the kernel-mode overlay object to modify.

### `OverlayInfo` [in]

A [D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo) structure that describes modification information for the kernel-mode overlay object.

## See also

[D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo)

[pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb)

[pfnUpdateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlaycb)