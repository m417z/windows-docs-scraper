# _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3 structure

## Description

Used in a call to the [DxgkDdiCheckMultiPlaneOverlaySupport3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3) function to check details on hardware support for multi-plane overlays.

## Members

### `PlaneCount`

The number of input planes to be enabled.

### `ppPlanes`

An array of pointers pointing to a DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE3 structure that specifies support attributes that the hardware provides for multi-plane overlays.

### `PostCompositionCount`

The number of VidPnSources for which we want to apply post composition transforms.

### `ppPostComposition`

An array of pointers pointing to a DXGK_CHECK_MULTIPLANE_OVERLAY_POST_COMPSOTION_WITH_SOURCE structure that specifies transforms that should be applied after the planes are composed.

### `Supported`

TRUE if the multi-plane overlay configuration can be supported, otherwise FALSE.

### `ReturnInfo`

Specifies additional information.