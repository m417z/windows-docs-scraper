# ID3D11VideoContext::VideoProcessorSetStreamLumaKey

## Description

Sets the luma key for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

Specifies whether luma keying is enabled.

### `Lower` [in]

The lower bound for the luma key. The valid range is [0…1]. If *Enable* is **FALSE**, this parameter is ignored.

### `Upper` [in]

The upper bound for the luma key. The valid range is [0…1]. If *Enable* is **FALSE**, this parameter is ignored.

## Remarks

To use this feature, the driver must support luma keying, indicated by the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_LUMA_KEY** capability flag. To query for this capability, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps). In addition, if the input format is RGB, the device must support the **D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_RGB_LUMA_KEY** capability.

The values of *Lower* and *Upper* give the lower and upper bounds of the luma key, using a nominal range of [0...1]. Given a format with *n* bits per channel, these values are converted to luma values as follows:

`val = f * ((1 << n)-1)`

Any pixel whose luma value falls within the upper and lower bounds (inclusive) is treated as transparent.

For example, if the pixel format uses 8-bit luma, the upper bound is calculated as follows:

`BYTE Y = BYTE(max(min(1.0, Upper), 0.0) * 255.0)`

Note that the value is clamped to the range [0...1] before multiplying by 255.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)