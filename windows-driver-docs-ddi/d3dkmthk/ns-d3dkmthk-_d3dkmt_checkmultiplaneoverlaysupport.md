# D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT structure

This structure has been replaced by [**D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_check_multiplane_overlay_plane3).

## Description

Check for multiplane overlay support.

## Members

### `hDevice`

A handle to the device.

### `PlaneCount`

The number of resources to pin.

### `pOverlayPlanes`

Array of pointers to overlay planes.

### `Supported`

Indicates support.

### `ReturnInfo`

The return info.

## See also

[**D3DKMTCheckMultiPlaneOverlaySupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckmultiplaneoverlaysupport)