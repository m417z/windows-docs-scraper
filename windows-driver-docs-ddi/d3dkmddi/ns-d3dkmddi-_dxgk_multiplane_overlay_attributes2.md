# _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2 structure

> [!NOTE] This structure has been replaced by [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3).

## Description

**DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2** is used by the display miniport driver to specify overlay plane attributes.

## Members

### `Flags`

Specifies a combination of flip operations by performing a bitwise OR operation on the values in the [DXGK_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_flags) enumeration.

### `SrcRect`

Specifies the source rectangle relative to the source resource.

### `DstRect`

Specifies the destination rectangle relative to the monitor resolution.

### `ClipRect`

Specifies any additional clipping region relative to **DstRect**
after the data has been stretched according to the values of **SrcRect** and **DstRect**.

The driver and hardware can use the **ClipRect** member to apply a common stretch factor
as the clipping changes when an application occludes part of the **DstRect** destination rectangle.

### `Rotation`

Specifies the clockwise rotation of the overlay plane, given as a value from the [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation) enumeration.

### `Blend`

Specifies the blend mode that applies to this overlay plane and the plane beneath it, given as a value from the [DXGK_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_blend) enumeration.

### `VideoFrameFormat`

Specifies the overlay plane's video frame format, given as a value from the [DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_video_frame_format) enumeration.

### `ColorSpaceType`

Specifies the color space configuration, given as a value from the [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) enumeration.

### `StereoFormat`

Specifies the overlay plane's video frame format, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_format) enumeration.

### `StereoLeftViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoBaseViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoFlipMode`

Specifies the overlay plane's stereo flip mode, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_flip_mode) enumeration.

### `StretchQuality`

Specifies the overlay plane's stretch quality, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stretch_quality) enumeration.

### `Reserved1`

*ColorKey*

Specifies the color key value used when color key blending is enabled for legacy overlays.

## See also

[D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[DXGK_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_blend)

[DXGK_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_flags)

[DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_flip_mode)

[DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_format)

[DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stretch_quality)

[DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_video_frame_format)