# ID3D11VideoContext::VideoProcessorSetStreamOutputRate

## Description

Sets the rate at which the video processor produces output frames for an input stream.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `OutputRate` [in]

The output rate, specified as a [D3D11_VIDEO_PROCESSOR_OUTPUT_RATE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_output_rate) value.

### `RepeatFrame` [in]

Specifies how the driver performs frame-rate conversion, if required.

| Value | Meaning |
| --- | --- |
| **TRUE** | Repeat frames. |
| **FALSE** | Interpolate frames. |

### `pCustomRate` [in]

A pointer to a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure. If *OutputRate* is **D3D11_VIDEO_PROCESSOR_OUTPUT_RATE_CUSTOM**, this parameter specifies the exact output rate. Otherwise, this parameter is ignored and can be **NULL**.

## Remarks

The standard output rates are normal frame-rate (**D3D11_VIDEO_PROCESSOR_OUTPUT_RATE_NORMAL**) and half frame-rate (**D3D11_VIDEO_PROCESSOR_OUTPUT_RATE_HALF**). In addition, the driver might support custom rates for rate conversion or inverse telecine. To get the list of custom rates, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCustomRate](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcustomrate).

Depending on the output rate, the driver might need to convert the frame rate. If so, the value of *RepeatFrame* controls whether the driver creates interpolated frames or simply repeats input frames.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)