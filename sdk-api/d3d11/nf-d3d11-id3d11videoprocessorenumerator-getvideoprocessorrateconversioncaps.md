# ID3D11VideoProcessorEnumerator::GetVideoProcessorRateConversionCaps

## Description

Returns a group of video processor capabilities that are associated with frame-rate conversion, including deinterlacing and inverse telecine.

## Parameters

### `TypeIndex` [in]

The zero-based index of the group to retrieve. To get the maximum index, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **RateConversionCapsCount** member of the [D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps) structure.

### `pCaps` [out]

A pointer to a [D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_rate_conversion_caps) structure that receives the frame-rate conversion capabilities.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The capabilities defined in the [D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_rate_conversion_caps) structure are interdependent. Therefore, the driver can support multiple, distinct groups of these capabilities.

## See also

[ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator)