# IMFPMediaPlayer::SetVideoSourceRect

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the video source rectangle.

MFPlay clips the video to this rectangle and stretches the rectangle to fill the video window.

## Parameters

### `pnrcSource` [in]

Pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle. This rectangle defines which portion of the video is displayed. It is specified in normalized coordinates, which are defined as follows:

* The upper-left corner of the video image is (0, 0).
* The lower-right corner of the video image is (1, 1).

To display the entire image, set the source rectangle to {0, 0, 1, 1}. This is the default value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The current media item does not contain video. |
| **MF_E_SHUTDOWN** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

MFPlay stretches the source rectangle to fill the entire video window. By default, MFPlay maintains the source's correct aspect ratio, letterboxing if needed. The letterbox color is controlled by the [IMFPMediaPlayer::SetBorderColor](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setbordercolor) method.

This method fails if no media item is currently set, or if the current media item does not contain video.

To set the video position before playback starts, call this method inside your event handler for the **MFP_EVENT_TYPE_MEDIAITEM_SET** event. For more information, see [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent).

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)