# IAMAnalogVideoDecoder::put_OutputEnable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_OutputEnable` method enables or disables the video port bus.

## Parameters

### `lOutputEnable` [in]

Specifies whether the bus is enabled. Use one of the following values.

| Value | Description |
| --- | --- |
| 0 | Disable the video port bus. |
| 1 | Enable the video port bus. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_PROP_ID_UNSUPPORTED** | The device does not support this method. |
| **S_OK** | Success. |

## Remarks

This method applies only to devices that use a shared video port bus. If the value is 1, the device will actively drive the video port bus. If the value is zero, the device will be tri-stated.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAnalogVideoDecoder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamanalogvideodecoder)