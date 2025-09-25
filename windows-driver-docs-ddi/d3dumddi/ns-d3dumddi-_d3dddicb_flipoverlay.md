# _D3DDDICB_FLIPOVERLAY structure

## Description

The D3DDDICB_FLIPOVERLAY structure describes a new allocation to display for the overlay.

## Members

### `hKernelOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the [pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb) function and that identifies the kernel-mode overlay object to be flipped.

### `hSource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the source allocation to be displayed.

### `pPrivateDriverData` [in]

A pointer to a block of private data, which is passed from the user-mode display driver to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that is pointed to by **pPrivateDriverData**.

## See also

[pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb)

[pfnFlipOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlaycb)