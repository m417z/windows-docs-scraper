## Description

Specifies a Direct3D 11 video feature or feature set to query about. When you want to query for the level to which an adapter supports a feature, pass one of these values to [ID3D11VideoDevice2::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11videodevice2-checkfeaturesupport).

## Constants

### `D3D11_FEATURE_VIDEO_DECODER_HISTOGRAM:0`

Retrieves the supported components, bin count, and counter bit depth for the a decode histogram with the specified decode profile, resolution, and format. The associated data structure is [D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d11_4/ns-d3d11_4-d3d11_feature_data_video_decoder_histogram).

## Remarks

## See also

[ID3D11VideoDevice2::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11videodevice2-checkfeaturesupport)