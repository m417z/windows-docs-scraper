# DXVAHD_STREAM_STATE_FILTER_DATA structure

## Description

Specifies the level for a filtering operation on a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) input stream.

## Members

### `Enable`

**If TRUE**, the filter is enabled. Otherwise, **the filter is disabled**.

### `Level`

The level for the filter. The meaning of this value depends on the implementation. To get the range and default value of a particular filter, call the [IDXVAHD_Device::GetVideoProcessorFilterRange](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorfilterrange) method.

If the **Enable** member is **FALSE**, the **Level** member is ignored.

## Remarks

For a list of image filters that are defined for DXVA-HD, see [DXVAHD_FILTER](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_filter). The device might not support every type of image filter. To find out whether the device supports a particular filter, call the [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) method and check the **FilterCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

#### Examples

```cpp
HRESULT DXVAHD_SetFilterValue(
    IDXVAHD_VideoProcessor *pVP,
    UINT stream,
    DXVAHD_FILTER filter,
    BOOL bEnable,
    INT value
    )
{
    DXVAHD_STREAM_STATE_FILTER_DATA data = { bEnable, value };

    DXVAHD_STREAM_STATE state = static_cast<DXVAHD_STREAM_STATE>(DXVAHD_STREAM_STATE_FILTER_BRIGHTNESS + filter);

    HRESULT hr = pVP->SetVideoProcessStreamState(
        stream,
        state,
        sizeof(data),
        &data
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