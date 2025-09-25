# IAMAudioInputMixer::put_Enable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Enable` method enables or disables an input.

## Parameters

### `fEnable` [in]

Specifies whether to enable or disable the input. Use one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | Enable the input. |
| **FALSE** | Disable the input. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

If an input is enabled, it is mixed into the recorded signal.

This method applies to specific input pins on the [Audio Capture Filter](https://learn.microsoft.com/windows/desktop/DirectShow/audio-capture-filter), so the filter itself returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::get_Enable](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_enable)