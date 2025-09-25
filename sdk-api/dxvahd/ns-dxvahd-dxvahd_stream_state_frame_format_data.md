# DXVAHD_STREAM_STATE_FRAME_FORMAT_DATA structure

## Description

Specifies how a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) input stream is interlaced.

## Members

### `FrameFormat`

The video interlacing, specified as a [DXVAHD_FRAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_frame_format) value.

The default state value is **DXVAHD_FRAME_FORMAT_PROGRESSIVE** (progressive frames).

## Remarks

Some devices do not support interlaced RGB. Interlaced RGB support is indicated by the **DXVAHD_INPUT_FORMAT_CAPS_RGB_INTERLACED** capability flag. If the device does not support interlaced RGB, it treats all RGB input streams as progressive frames.

Some devices do not support interlaced formats with palettized color. This support is indicated by the **DXVAHD_INPUT_FORMAT_CAPS_PALETTE_INTERLACED** flag. If the device does not support this capability, all palettized input streams are treated as progressive frames.

To get the device's capabilities, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) and check the **InputFormatCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

#### Examples

```cpp
HRESULT DXVAHD_SetFrameFormat(
    IDXVAHD_VideoProcessor *pVP,
    UINT stream,
    DXVAHD_FRAME_FORMAT format
    )
{
    DXVAHD_STREAM_STATE_FRAME_FORMAT_DATA frame_format = { format };

    HRESULT hr = pVP->SetVideoProcessStreamState(
        stream,
        DXVAHD_STREAM_STATE_FRAME_FORMAT,
        sizeof(frame_format),
        &frame_format
        );

    return hr;
}

```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)