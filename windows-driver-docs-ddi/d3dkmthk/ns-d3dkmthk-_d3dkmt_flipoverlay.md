# _D3DKMT_FLIPOVERLAY structure

## Description

The D3DKMT_FLIPOVERLAY structure describes a new allocation to display for the overlay.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device that the overlay is associated with.

### `hOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the create-overlay function and that identifies the kernel-mode overlay object to be flipped.

### `hSource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the source allocation to be displayed.

### `pPrivateDriverData` [in]

A pointer to a block of private data, which is passed from the OpenGL ICD to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that **pPrivateDriverData** points to.

## See also

[D3DKMTFlipOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtflipoverlay)