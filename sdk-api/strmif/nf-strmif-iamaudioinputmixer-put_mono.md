# IAMAudioInputMixer::put_Mono

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Mono` method combines all channels into a mono signal.

## Parameters

### `fMono` [in]

Specifies mono or multichannel. Use one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | Mono |
| **FALSE** | Multichannel |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Error setting mono control. |
| **S_OK** | Success. |

## Remarks

In mono mode, a stereo recording of this input will have the same data in both channels. The result will be a mixture of the left and right signals.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::get_Mono](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_mono)