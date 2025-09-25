# _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES structure

> [!NOTE] This structure has been replaced by [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3).

## Description

Used by the display miniport driver to specify overlay plane attributes.

## Members

### `Flags`

Specifies a flip operation as one of the applicable constant values in the [DXGK_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_flags) enumeration.

### `SrcRect`

Specifies the source rectangle, of type [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect), relative to the source resource.

### `DstRect`

Specifies the destination rectangle, of type [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect), relative to the monitor resolution.

### `ClipRect`

Specifies any additional clipping, of type [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect), relative to the **DstRect** rectangle, after the data has been stretched according to the values of **SrcRect** and **DstRect**.

The driver and hardware can use the **ClipRect** member to apply a common stretch factor as the clipping changes when an app occludes part of the **DstRect** destination rectangle.

### `Rotation`

Specifies the clockwise rotation of the overlay plane, given as a value from the [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation) enumeration.

### `Blend`

Specifies the blend mode that applies to this overlay plane and the plane beneath it, given as a value from the [DXGK_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_blend) enumeration.

### `NumFilters`

Optionally specifies the number of filters that the driver and hardware implement on the overlay plane. Note that the operating system ignores this member.

### `pFilters`

An optional pointer to a buffer that specifies the filters that the driver and hardware implement on the overlay plane. Note that the operating system ignores this member.

### `VideoFrameFormat`

Specifies the overlay plane's video frame format, given as a value from the [DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_video_frame_format) enumeration.

**Note** This value must always be **DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT_PROGRESSIVE**. The operating system does not support the other enumeration values.

### `YCbCrFlags`

Specifies YUV range and conversion info given as a value from the [DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_ycbcr_flags) enumeration.

### `StereoFormat`

Specifies the overlay plane's video frame format, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_format) enumeration.

**Note** This value must always be **DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT_MONO**. The operating system does not support the other enumeration values.

### `StereoLeftViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoBaseViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoFlipMode`

Specifies the overlay plane's stereo flip mode, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_flip_mode) enumeration.

**Note** This value must always be **DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_NONE**. The operating system does not support the other enumeration values.

### `StretchQuality`

Specifies the overlay plane's stretch quality, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stretch_quality) enumeration.

## See also

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[DXGK_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_blend)

[DXGK_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_flags)

[DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_flip_mode)

[DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stereo_format)

[DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stretch_quality)

[DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_video_frame_format)

[DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_ycbcr_flags)