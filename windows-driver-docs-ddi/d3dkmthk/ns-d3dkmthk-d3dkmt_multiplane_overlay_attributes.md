# D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES structure

## Description

The **D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES** structure contains multiplane overlay attributes.

## Members

### `Flags`

Flag options.

### `SrcRect`

Specifies the source rectangle.

### `DstRect`

Specifies the destination rectangle.

### `ClipRect`

Specifies any additional clipping.

### `Rotation`

Specifies the clockwise rotation of the overlay plane.

### `Blend`

Specifies the blend mode that applies to this overlay plane and the plane beneath it.

### `DirtyRectCount`

The number of dirty rectangles.

### `pDirtyRects`

A pointer to an array of dirty rectangles.

### `NumFilters`

Optionally specifies the number of filters that the driver and hardware implement on the overlay plane.

### `pFilters`

An optional pointer to a buffer that specifies the filters that the driver and hardware implement on the overlay plane.

### `VideoFrameFormat`

Specifies the overlay plane's video frame format, given as a value from the [D3DKMT_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-d3dkmt_multiplane_overlay_video_frame_format) enumeration.

### `YCbCrFlags`

Specifies YUV range and conversion info given as a value from the [D3DKMT_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-d3dkmt_multiplane_overlay_ycbcr_flags) enumeration.

### `StereoFormat`

Specifies the overlay plane's video frame format, given as a value from the [D3DKMT_MULTIPLANE_OVERLAY_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-d3dkmt_multiplane_overlay_stereo_format) enumeration.

### `StereoLeftViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoBaseViewFrame0`

Reserved for system use. Must always be **FALSE**.

### `StereoFlipMode`

Specifies the overlay plane's stereo flip mode, given as a value from the [_DXGKMT_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_dxgkmt_multiplane_overlay_stereo_flip_mode) enumeration.

### `StretchQuality`

Specifies the overlay plane's stretch quality, given as a value from the [_DXGKMT_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_dxgkmt_multiplane_overlay_stretch_quality) enumeration.

## Remarks

## See also