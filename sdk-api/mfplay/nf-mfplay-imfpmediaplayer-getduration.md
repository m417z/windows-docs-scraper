# IMFPMediaPlayer::GetDuration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the playback duration of the current media item.

## Parameters

### `guidPositionType` [in]

Specifies the unit of time for the duration. The following value is defined.

| Value | Meaning |
| --- | --- |
| **MFP_POSITIONTYPE_100NS** | 100-nanosecond units.<br><br>The value returned in *pvDurationValue* is a **ULARGE_INTEGER**.<br><br>* Variant type (**vt**): **VT_UI8**<br>* Variant member: **uhVal** |

### `pvDurationValue` [out]

Pointer to a **PROPVARIANT** that receives the duration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The media source does not have a duration. This error can occur with a live source, such as a video camera. |
| **MF_E_INVALIDREQUEST** | There is no current media item. |

## Remarks

This method calculates the playback duration, taking into account the start and stop times for the media item. To set the start and stop times, call [IMFPMediaItem::SetStartStopPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstartstopposition) on the media item. To get the actual duration of the underlying media file, regardless of start and stop times, call [IMFPMediaItem::GetDuration](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getduration).

For example, suppose that you load a 30-second audio file and set the start time equal to 2 seconds and stop time equal to 10 seconds. The [IMFPMediaItem::GetDuration](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getduration) method will return 30 seconds, but the **IMFPMediaPlayer::GetDuration** method will return 8 seconds.

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)