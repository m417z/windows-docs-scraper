# IMFPMediaItem::SetStreamSelection

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Selects or deselects a stream.

## Parameters

### `dwStreamIndex` [in]

Zero-based index of the stream. To get the number of streams, call [IMFPMediaItem::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getnumberofstreams).

### `fEnabled` [in]

Specify whether to select or deselect the stream.

| Value | Meaning |
| --- | --- |
| **TRUE** | The stream is selected. During playback, this stream will play. |
| **FALSE** | The stream is not selected. During playback, this stream will not play. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use this method to change which streams are selected. The change goes into effect the next time that [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem) is called with this media item. If the media item is already set on the player, the change does not happen unless you call **SetMediaItem** again with this media item.

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)