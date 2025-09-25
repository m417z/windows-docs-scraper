# _D3DDDICB_DESTROYOVERLAY structure

## Description

The D3DDDICB_DESTROYOVERLAY structure contains the handle to the overlay to destroy.

## Members

### `hKernelOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the [pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb) function and that identifies the kernel-mode overlay object to destroy.

## See also

[pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb)

[pfnDestroyOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyoverlaycb)