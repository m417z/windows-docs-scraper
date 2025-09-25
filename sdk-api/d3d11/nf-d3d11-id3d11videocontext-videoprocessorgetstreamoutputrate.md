# ID3D11VideoContext::VideoProcessorGetStreamOutputRate

## Description

Gets the rate at which the video processor produces output frames for an input stream.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `pOutputRate` [out]

Receives a [D3D11_VIDEO_PROCESSOR_OUTPUT_RATE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_output_rate) value that specifies the output rate.

### `pRepeatFrame` [out]

Receives a Boolean value that specifies how the driver performs frame-rate conversion, if required.

| Value | Meaning |
| --- | --- |
| **TRUE** | Repeat frames. |
| **FALSE** | Interpolate frames. |

### `pCustomRate` [out]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure. If the output rate is **D3D11_VIDEO_PROCESSOR_OUTPUT_RATE_CUSTOM**, the method fills in this structure with the exact output rate. Otherwise, this parameter is ignored.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)