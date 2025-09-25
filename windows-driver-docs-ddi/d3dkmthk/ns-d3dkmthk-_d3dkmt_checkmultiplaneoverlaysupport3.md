# D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 structure

## Description

The **D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3** structure is passed to [**D3DKMTCheckMultiPlaneOverlaySupport3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckmultiplaneoverlaysupport3) to check for multiplane overlay support.

## Members

### `hAdapter`

[in] A handle to the graphics adapter.

### `hDevice`

[in] A handle to the device.

### `PlaneCount`

[in] The number of overlay plane pointers that **ppOverlayPlanes** points to.

### `ppOverlayPlanes`

[in] Array of pointers to [**D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_check_multiplane_overlay_plane3) structures that describe the overlay planes.

### `PostCompositionCount`

[in] The number of pointers that **ppPostComposition** points to.

### `ppPostComposition`

[in] Array of pointers to [**D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION_WITH_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplane_overlay_post_composition_with_source) structures.

### `Supported`

[out] Boolean value that indicates support.

### `ReturnInfo`

[out] A [**D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_check_multiplane_overlay_support_return_info) structure in which details are returned when **Supported** is FALSE.

## See also

[**D3DKMTCheckMultiPlaneOverlaySupport3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckmultiplaneoverlaysupport3)