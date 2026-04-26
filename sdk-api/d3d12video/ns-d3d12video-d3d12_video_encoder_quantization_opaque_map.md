## Description

Contains a GPU-resolved quantization map for the current frame to be used instead of the existing CPU buffer pRateControlQPMap parameters. The user must check support for D3D12_FEATURE_VIDEO_ENCODER_QPMAP_INPUT before using this feature.

## Members

### `pOpaqueQuantizationMap`

Pointer to an ID3D12Resource containing the quantization map. When not NULL, this supersedes the existing CPU buffer pRateControlQPMap picture control structure parameters. Must be first resolved using [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Remarks

## See also