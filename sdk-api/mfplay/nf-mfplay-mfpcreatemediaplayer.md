# MFPCreateMediaPlayer function

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Creates a new instance of the MFPlay player object.

## Parameters

### `pwszURL` [in]

Null-terminated string that contains the URL of a media file to open. This parameter can be **NULL**. If the parameter is **NULL**, *fStartPlayback* must be **FALSE**.

If this parameter is **NULL**, you can open a URL later by calling [IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl).

### `fStartPlayback` [in]

If **TRUE**, playback starts automatically. If **FALSE**, playback does not start until the application calls [IMFMediaPlayer::Play](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-play).

If *pwszURL* is **NULL**, this parameter is ignored.

### `creationOptions` [in]

Bitwise **OR** of zero of more flags from the [_MFP_CREATION_OPTIONS](https://learn.microsoft.com/windows/win32/api/mfplay/ne-mfplay-_mfp_creation_options) enumeration.

### `pCallback` [in]

Pointer to the [IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback) interface of a callback object, implemented by the application. Use this interface to get event notifications from the MFPlay player object. This parameter can be **NULL**. If the parameter is **NULL**, the application will not receive event notifications from the player object.

### `hWnd` [in]

A handle to a window where the video will appear. For audio-only playback, this parameter can be **NULL**.

The window specified by *hWnd* is used for the first selected video stream in the source. If the source has multiple video streams, you must call [IMFPMediaItem::SetStreamSink](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstreamsink) to render any of the video streams after the first.

If *hWnd* is **NULL**, MFPlay will not display any video unless the application calls [IMFPMediaItem::SetStreamSink](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstreamsink) to specify a media sink for the video stream.

### `ppMediaPlayer` [out]

Receives a pointer to the [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) interface. The caller must release the interface. This parameter can be **NULL**. If this parameter is **NULL**, *fStartPlayback* must be **TRUE** and *pwszURL* cannot be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this function, call **CoIntialize(Ex)** from the same thread to initialize the COM library.

Internally, **MFPCreateMediaPlayer** calls [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) to initialize the Microsoft Media Foundation platform. When the player object is destroyed, it calls [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) to shut down the platform. It is not necessary for an application to call **MFStartup** or **MFShutdown** when using MFPlay.

**Note** If you use other Media Foundation APIs outside the life time of the player object, then your application should call [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) and [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)