## Description

The **D3D12DDICAPS_VIDEO_ENCODER_INPUT_FORMAT_DATA_0080_2** structure is used to query whether a specified video encoding input format is supported.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the codec to check support for.

### `Profile`

[in] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that specifies the profile to check support for.

### `Format`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the format setting to check support for.

> [!NOTE]
>
> This format definition includes the subsampling and bit-depth modes for the video encoding session. The driver is not responsible for handling the input subsampling/color conversion stages of video encoding; this is the responsibility of the host.

### `IsSupported`

[out] Indicates whether the given feature values are supported.

## Remarks

Format support for 4:2:0 with 8- and 10-bitdepth samples should be encoded using the following formats:

* DXGI_FORMAT_P010
* DXGI_FORMAT_NV12

The D3D runtime calls [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with [**D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_INPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) specified as the capability type.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)