# _D3DKMT_DESTROYOVERLAY structure

## Description

The D3DKMT_DESTROYOVERLAY structure contains the handle to the overlay to destroy.

## Members

### `hDevice` [in]

A handle to the device that the overlay is associated with.

### `hOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the create-overlay function and that identifies the kernel-mode overlay object to destroy.

## See also

[D3DKMTDestroyOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyoverlay)