# IMFPMediaItem::HasVideo

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Queries whether the media item contains a video stream.

## Parameters

### `pfHasVideo` [out]

Receives the value **TRUE** if the media item contains at least one video stream, or **FALSE** otherwise.

### `pfSelected` [out]

Receives the value **TRUE** if at least one video stream is selected, or **FALSE** otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To select or deselect streams before playback starts, call [IMFPMediaItem::SetStreamSelection](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstreamselection).

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)