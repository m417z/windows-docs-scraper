# D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 structure

## Description

The **D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2** structure is passed to [**D3DKMTCheckMultiPlaneOverlaySupport2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckmultiplaneoverlaysupport2) to check for multiplane overlay support.

## Members

### `hAdapter`

[in] A handle to the graphics adapter.

### `hDevice`

[in] A handle to the device.

### `PlaneCount`

[in] The number of overlay planes that **pOverlayPlanes** points to.

### `pOverlayPlanes`

[in] Pointer to an array of [**D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_check_multiplane_overlay_plane2) structures that describe the overlay planes.

### `Supported`

[out] Boolean value that indicates support.

### `ReturnInfo`

[out] A [**D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_check_multiplane_overlay_support_return_info) structure in which details are returned when **Supported** is FALSE.

## See also

[**D3DKMTCheckMultiPlaneOverlaySupport2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckmultiplaneoverlaysupport2)