# _D3DKMT_GETOVERLAYSTATE structure

## Description

The D3DKMT_GETOVERLAYSTATE structure describes parameters that the [D3DKMTGetOverlayState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetoverlaystate) function uses to retrieve status about an overlay.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device that the overlay is associated with.

### `hOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the create-overlay function and that identifies the kernel-mode overlay object to retrieve status about.

### `OverlayEnabled` [out]

A Boolean variable that receives **TRUE** if the overlay is enabled and **FALSE** if the overlay is disabled.

## See also

[D3DKMTGetOverlayState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetoverlaystate)