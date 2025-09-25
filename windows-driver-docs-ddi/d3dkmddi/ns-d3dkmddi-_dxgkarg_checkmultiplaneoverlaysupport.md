# _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT structure

> [!NOTE] This structure has been replaced by [DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport3)

## Description

Used in a call to the [DxgkDdiCheckMultiPlaneOverlaySupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport) function to check details on hardware support for multiplane overlays.

## Members

### `PlaneCount`

The number of overlay planes that the hardware supports.

### `pPlanes`

A pointer to a [DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_check_multiplane_overlay_support_plane) structure that specifies support attributes that the hardware provides for multiplane overlays.

### `Supported`

**TRUE** if the hardware supports multiplane overlays, otherwise **FALSE**.

### `ReturnInfo`

Specifies limitations on hardware support of multiplane overlays.

## See also

[DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_check_multiplane_overlay_support_plane)

[DxgkDdiCheckMultiPlaneOverlaySupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport)