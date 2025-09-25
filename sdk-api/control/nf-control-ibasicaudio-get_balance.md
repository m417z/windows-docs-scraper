# IBasicAudio::get_Balance

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_Balance` method retrieves the balance for the audio signal.

## Parameters

### `plBalance` [out]

Pointer to a variable that receives the balance.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | The filter graph does not contain an audio renderer filter. (Possibly the source does not contain an audio stream.) |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

The balance ranges from -10,000 to 10,000. The value -10,000 means the right channel is attenuated by 100 dB and is effectively silent. The value 10,000 means the left channel is silent. The neutral value is 0, which means that both channels are at full volume. When one channel is attenuated, the other remains at full volume.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicAudio Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicaudio)