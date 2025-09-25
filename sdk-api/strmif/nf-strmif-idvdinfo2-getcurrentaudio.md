# IDvdInfo2::GetCurrentAudio

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentAudio` method retrieves the number of available audio streams and the number of the currently selected audio stream.

## Parameters

### `pulStreamsAvailable` [out]

Receives the number of available audio streams.

### `pulCurrentStream` [out]

Receives the currently selected audio stream number in the current title.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Input arguments are invalid. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized or not in a valid domain. |

## Remarks

To get the available audio languages on the disc, call `GetCurrentAudio` and then call [GetAudioLanguage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudiolanguage) for each stream, starting from zero through (*pulStreamsAvailable* - 1) to get the language content.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[EC_DVD_AUDIO_STREAM_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-audio-stream-change)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)