# _D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES structure

## Description

Used by the user-mode display driver to specify overlay plane attributes.

## Members

### `Flags`

Specifies a flip operation as one of the applicable values in the [D3DDDI_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_multiplane_overlay_flags) enumeration.

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

Specifies the blend mode that applies to this overlay plane and the plane beneath it, given as a value from the [D3DDDI_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_multiplane_overlay_blend) enumeration.

### `DirtyRectCount`

The number of dirty rectangles specified for the overlay plane. If zero, the entire plane is considered dirty.

### `pDirtyRects`

A pointer to an array of dirty rectangles ([RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)s), relative to the source rectangle **SrcRect**, that indicate the portion of the overlay plane that has changed.

The driver can use this member to perform optimizations, though it's not required to use the dirty rectangle info. However, the driver should never fail a function call based on the provided dirty rectangles.

### `NumFilters`

Optionally specifies the number of filters that the driver and hardware implement on the overlay plane. Note that the operating system ignores this member.

### `pFilters`

An optional pointer to a buffer that specifies the filters that the driver and hardware implement on the overlay plane. Note that the operating system ignores this member.

### `VideoFrameFormat`

Specifies the overlay plane's video frame format, given as a value from the [D3DDDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_video_frame_format) enumeration.

**Note** This value must always be **DXGI_DDI_MULIIPLANE_OVERLAY_VIDEO_FRAME_FORMAT_PROGRESSIVE**. The operating system does not support the other enumeration values.

### `YCbCrFlags`

Specifies YUV range and conversion info given as a value from the [D3DDDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_ycbcr_flags) enumeration.

### `StretchQuality`

Specifies the overlay plane's stretch quality, given as a value from the [D3DDDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_stretch_quality) enumeration.

## See also

[D3DDDI_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_multiplane_overlay_blend)

[D3DDDI_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_multiplane_overlay_flags)

[D3DDDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_stretch_quality)

[D3DDDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_video_frame_format)

[D3DDDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_multiplane_overlay_ycbcr_flags)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)