# _D3DKMDT_VIDPN_PRESENT_PATH structure

## Description

The D3DKMDT_VIDPN_PRESENT_PATH structure contains information about a video present path.

## Members

### `VidPnSourceId`

The identifier of the path's video present source.

### `VidPnTargetId`

The identifier of the path's video present target.

### `ImportanceOrdinal`

A [D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_importance) enumerator that specifies the importance of the path relative to other paths. For example, the path presenting the primary view might have higher importance than other paths so that it will be assigned the best source and target mode sets. Path importance ordinal numbers are unique within a given video present network (VidPN) topology.

### `ContentTransformation`

 A [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) enumerator that indicates the transformation applied to the content presented on the video present path.

### `VisibleFromActiveTLOffset`

A D3DKMDT_2DOFFSET structure that contains the offset, in pixels, from the top-left corner of the video signal's active pixels to the top-left corner of the monitor's visible pixels. The D3DKMDT_2DOFFSET data type is defined in *D3dkmdt.h* as a [D3DKMDT_2DREGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_2dregion) structure.

### `VisibleFromActiveBROffset`

A D3DKMDT_2DOFFSET structure that contains the offset, in pixels, from the lower-right corner of the video signal's active pixels to the lower-right corner of the monitor's visible pixels.

### `VidPnTargetColorBasis`

A [D3DKMDT_COLOR_BASIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_color_basis) enumerator that specifies the color basis used by the path's video present target.

### `VidPnTargetColorCoeffDynamicRanges`

A [D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_color_coeff_dynamic_ranges) structure that specifies a range for each channel in the color basis used by the path's video present target.

### `Content`

A value from the [D3DKMDT_VIDPN_PRESENT_PATH_CONTENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_content) enumeration that indicates the type of content, graphics or video, displayed by the path.

### `CopyProtection`

A [D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_copyprotection) structure that describes the copy protection supported by, and currently active on, the path.

### `GammaRamp`

A [D3DKMDT_GAMMA_RAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gamma_ramp) structure that contains a description of a gamma lookup table and a pointer to the lookup table.

## Remarks

A video present path represents a connection between a video present source (view) and a video present target (output) on a display adapter. For more information about video present networks, paths, sources, and targets, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[DxgkDdiUpdateActiveVidPnPresentPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath)