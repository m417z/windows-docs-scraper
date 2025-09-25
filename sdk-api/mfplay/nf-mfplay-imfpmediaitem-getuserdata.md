# IMFPMediaItem::GetUserData

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the application-defined value stored in the media item.

## Parameters

### `pdwUserData` [out]

Receives the application-defined value for the media item.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can assign this value when you first create the media item, by specifying it in the *dwUserData* parameter of the [IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl) or [IMFPMediaPlayer::CreateMediaItemFromObject](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromobject) method. To update the value, call [IMFPMediaItem::SetUserData](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setuserdata).

This method can be called after the player object is shut down.

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)