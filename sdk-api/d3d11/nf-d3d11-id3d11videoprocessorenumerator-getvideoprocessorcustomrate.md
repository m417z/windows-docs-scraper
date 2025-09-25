# ID3D11VideoProcessorEnumerator::GetVideoProcessorCustomRate

## Description

Gets a list of custom frame rates that a video processor supports.

## Parameters

### `TypeIndex` [in]

The zero-based index of the frame-rate capability group. To get the maxmum index, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps)  and check the **RateConversionCapsCount** member of the [D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps) structure.

### `CustomRateIndex` [in]

The zero-based index of the custom rate to retrieve. To get the maximum index, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorRateConversionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorrateconversioncaps) and check the **CustomRateCount** member of the [D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_rate_conversion_caps) structure.

This index value is always relative to the capability group specified in the *TypeIndex* parameter.

### `pRate` [out]

A pointer to a [D3D11_VIDEO_PROCESSOR_CUSTOM_RATE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_custom_rate) structure that receives the custom rate.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator)