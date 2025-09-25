# D3D12DDI_VIDEO_DECODE_SUPPORT_DATA_0020 structure

## Description

Specifies data used to determine support of hardware for a configuration. Used by the [PFND3D12DDI_VIDEO_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) callback function, with the *Type* parameter in [D3D12DDIARG_VIDEO_GETCAPS_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020) set to D3D12DDICAPS_TYPE_VIDEO_DECODE_SUPPORT.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Configuration`

The decode profile and bitstream encryption. For more information, see [D3D12DDI_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020).

### `Width`

The decode width of the source stream.

### `Height`

The decode height of the source stream.

### `DecodeFormat`

The DirectX resource data format to use as the decode format. If no decoder conversion is specified, this format is the output format.

### `FrameRate`

The frame rate of the video format. Used to help return performance hints in the **SupportFlags** member. A value of zero (0) means unknown.

### `BitRate`

The average bits per second data compression rate for the compressed video stream. This is used by the driver to determine whether the video can be decoded in real time. A value of zero (0) means unknown.

### `SupportFlags`

Supported flags. For more information, see [D3D12DDI_VIDEO_DECODE_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_support_flags_0020).

### `ConfigurationFlags`

Configuration flags. For more information, see [D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_configuration_flags_0020).

### `DecodeTier`

The tier supported by this configuration. For more information, see [D3D12DDI_VIDEO_DECODE_TIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_tier_0020).

## Remarks

This structure is retrieved through the [pfnGetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) callback function with the [D3D12DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type) set to a value of **D3D12DDICAPS_TYPE_VIDEO_DECODE_SUPPORT**.

## See also

[D3D12DDI_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_configuration_flags_0020)

**D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAGS**

[D3D12DDI_VIDEO_DECODE_SUPPORT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_support_flags_0020)

[D3D12DDI_VIDEO_DECODE_TIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_tier_0020)