# IMFPMediaItem::GetURL

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the URL that was used to create the media item.

## Parameters

### `ppwszURL` [out]

Receives a pointer to a null-terminated string that contains the URL. The caller must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOTFOUND** | No URL is associated with this media item. |
| **MF_E_SHUTDOWN** | The [IMFPMediaPlayer::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

This method applies when the application calls [IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl) to create a media item. If the application calls [IMFPMediaPlayer::CreateMediaItemFromObject](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromobject) to create a media item, the **GetURL** method for that media item returns **MF_E_NOTFOUND**.

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)