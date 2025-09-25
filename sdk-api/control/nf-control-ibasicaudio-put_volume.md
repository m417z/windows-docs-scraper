# IBasicAudio::put_Volume

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Volume` method sets the volume (amplitude) of the audio signal.

## Parameters

### `lVolume` [in]

Specifies the volume, as a number from –10,000 to 0, inclusive. Full volume is 0, and –10,000 is silence. Multiply the desired decibel level by 100. For example, –10,000 = –100 dB.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The underlying audio device returned an error. |
| **E_INVALIDARG** | The value of *lVolume* is invalid. |
| **E_NOTIMPL** | The filter graph does not contain an audio renderer filter. (Possibly the source does not contain an audio stream.) |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicAudio Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicaudio)