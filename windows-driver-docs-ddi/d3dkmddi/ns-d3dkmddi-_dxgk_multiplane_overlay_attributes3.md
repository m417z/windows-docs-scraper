# _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3 structure

## Description

A structure containing the attributes used for the image in a multiplane overlay.

## Members

### `Flags`

Specifies a combination of flip operations by Oring values in the [DXGK_MULTIPLANE_OVERLAY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_flags) enumeration.

### `SrcRect`

Specifies the source rectangle, of type RECT, relative to the source resource.

### `DstRect`

Specifies the destination rectangle, of type RECT, relative to the monitor resolution.

### `ClipRect`

Specifies additional clipping information, of type RECT, relative to the DstRect rectangle, after the data has been stretched according to the values of SrcRect and DstRect.

The driver and hardware can use the ClipRect member to apply a common stretch factor as the clipping changes when an app occludes part of the DstRect destination rectangle.

### `Rotation`

Specifies the clockwise rotation of the overlay plane, given as a value from the D3DDDI_ROTATION enumeration.

### `Blend`

Specifies the blend mode that applies to this overlay plane and the plane beneath it, given as a value from the [DXGK_MULTIPLANE_OVERLAY_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_blend) enumeration.

### `ColorSpaceType`

Specifies the color space configuration, given as a value from the [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) enumeration.

### `StretchQuality`

Specifies the overlay plane's stretch quality, given as a value from the [DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_multiplane_overlay_stretch_quality) enumeration.

### `SDRWhiteLevel`

Specifies the value in nits that the driver should to map sRGB 1.0.

For HDR content, this will always be 0.

For SDR (standard dynamic range) content, a value of 0 indicates that the driver should map sRGB 1.0 to the default value, which is 80 nits.

This value is ignored when not in HDR mode.

### `DirtyRectCnt`

The number of dirty rectangles of *pDirtyRects*.

### `pDirtyRects`

Pointer of the dirty rectangles.

## Remarks

WDDM 2.3 drivers need to check the SDRWhiteLevel value passed in the [CheckMultiPlaneOverlaySupport3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3) callback, and return unsupported if the hardware is unable to adjust the relative brightness of the SDR content.

When boosting the SDR content to the SDRWhiteLevel, the scaling must occur in linear space.