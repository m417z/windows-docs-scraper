# DXGI_DDI_MULTIPLANE_OVERLAY_FLAGS enumeration

## Description

The **DXGI_DDI_MULTIPLANE_OVERLAY_FLAGS** enumeration defines a set of flags that describe the characteristics and behaviors of a multiplane overlay.

## Constants

### `DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_VERTICAL_FLIP`

The overlay plane should flip the data vertically, making it appear upside-down.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_HORIZONTAL_FLIP`

The overlay plane should flip the data horizontally, making it appear as a right-to-left mirror image.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_FULLSCREEN_POST_COMPOSITION`

Indicates that the plane is to be stretched using panel fitter hardware.

This should only be set for plane 0.

Composition with other multi-plane overlay planes may be supported, but the ClipRects of those planes must be bound to the SourceRect of this plane.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_NO_SCANOUT_TRANFORMATION`

The runtime may request the driver to temporarily disable the transformation during the period of time where front-buffer rendering is desired.

A transformation occurs when contents are transferred from the application surface to a shadow surface in preparation for a flip operation. For more information, see [PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_prepare_scanout_transformation) and [PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_query_scanout_caps).

### -field

When set, this flag indicates that the overlay should not be presented as part of the normal rendering process.