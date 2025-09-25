# _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2 structure

> [!NOTE] This structure has been replaced by [DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport3)

## Description

**DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2** is passed to the [DxgkDdiCheckMultiPlaneOverlaySupport2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport2) function to determine whether a specific multi-plane overlay configuration is supported.

## Members

### `PlaneCount`

The number of planes to be enabled.

### `pPlanes`

A pointer to a [DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane_with_source)
structure that specifies support attributes that the hardware
provides for multi-plane overlays.

### `Supported`

**TRUE** if the multi-plane overlay configuration can be supported, otherwise **FALSE**.

### `ReturnInfo`

Specifies additional information.

## See also

[DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane_with_source)

[DxgkDdiCheckMultiPlaneOverlaySupport2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport2)