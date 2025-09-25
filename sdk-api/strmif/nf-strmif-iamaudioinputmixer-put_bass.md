# IAMAudioInputMixer::put_Bass

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Bass` method sets the bass equalization.

## Parameters

### `Bass` [in]

Specifies the gain, in decibels. A negative value specifies attenuation.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. Must be in range given by [IAMAudioInputMixer::get_BassRange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_bassrange). |

## Remarks

This method boosts or cuts the signal's bass before it is recorded, by the number of decibels specified in the *Bass* parameter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::get_Bass](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_bass)