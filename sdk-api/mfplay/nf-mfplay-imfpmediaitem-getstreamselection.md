# IMFPMediaItem::GetStreamSelection

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Queries whether a stream is selected to play.

## Parameters

### `dwStreamIndex` [in]

Zero-based index of the stream. To get the number of streams, call [IMFPMediaItem::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getnumberofstreams).

### `pfEnabled` [out]

Receives a Boolean value.

| Value | Meaning |
| --- | --- |
| **TRUE** | The stream is selected. During playback, this stream will play. |
| **FALSE** | The stream is not selected. During playback, this stream will not play. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To select or deselect a stream, call [IMFPMediaItem::SetStreamSelection](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstreamselection).

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)