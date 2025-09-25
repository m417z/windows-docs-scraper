# D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_DATA_0032 structure

## Description

Structure used to check if a color space conversion, format conversion, and scale are supported, and whether it is required for real-time reasons or reference buffer format.

## Members

### `NodeIndex`

In multi-adapter operation, the NodeIndex indicates which physical adapter of the device this operation applies to.

### `Configuration`

The decode profile and bitstream encryption. See [D3D12DDI_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020).

### `DecodeSample`

The source decoded as sample description. See [D3D12DDI_VIDEO_SAMPLE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_sample_description_0020).

### `OutputFormat`

The output sample description. See [D3D12DDI_VIDEO_FORMAT_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_format_description_0020).

### `FrameRate`

The frame rate of the video content. This is used by the driver to determine whether the video can be decoded in real-time.

### `BitRate`

The average bits per second data compression rate for the compressed video stream. This is used by the driver to determine whether the video can be decoded in real-time.

### `SupportFlags`

Supported flags. See [D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_conversion_support_flags_0020).

### `ScaleSupport`

Indicates the supported output size range for decode conversion. See [D3D12DDI_VIDEO_SCALE_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_scale_support_0032).

## Remarks

The check is made through [**pfnGetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with the [**D3D12DDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type) set to a value of **D3D12DDICAPS_TYPE_VIDEO_DECODE_CONVERSION_SUPPORT**.

If the color space and format conversion is reported, **SupportedFlags** will have D3D12DDI_VIDEO_DECODE_SUPPORT_FLAGS_SUPPORTED set. Callers should check **ScaleSupport** to understand if the scale is supported.

## See also

[D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_conversion_support_flags_0020)