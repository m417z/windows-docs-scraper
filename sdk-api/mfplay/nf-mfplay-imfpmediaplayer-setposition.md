# IMFPMediaPlayer::SetPosition

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the playback position.

## Parameters

### `guidPositionType` [in]

Unit of time for the playback position. The following value is defined.

| Value | Meaning |
| --- | --- |
| **MFP_POSITIONTYPE_100NS** | 100-nanosecond units. <br><br>The value of *pvPositionValue* must be a **LARGE_INTEGER**.<br><br>* Variant type (**vt**): **VT_I8**<br>* Variant member: **hVal** |

### `pvPositionValue` [in]

New playback position. The meaning and data type of this parameter are indicated by the *guidPositionType* parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **HRESULT_FROM_WIN32( ERROR_SEEK )** | The value of *pvPositionValue* is not valid. |
| **MF_E_INVALIDREQUEST** | No media item has been queued. |
| **MF_E_SHUTDOWN** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

If you call this method while playback is stopped, the new position takes effect after playback resumes.

This method completes asynchronously. When the operation completes, the application's [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback method is invoked. The event type is **MFP_EVENT_TYPE_POSITION_SET**.

If playback was started before **SetPosition** is called, playback resumes at the new position. If playback was paused, the video is refreshed to display the current frame at the new position.

If you make two consecutive calls to **SetPosition** with *guidPositionType* equal to **MFP_POSITIONTYPE_100NS**, and the second call is made before the first call has completed, the second call supersedes the first. The status code for the superseded call is set to **S_FALSE** in the event data for that call. This behavior prevents excessive latency from repeated calls to **SetPosition**, as each call may force the media source to perform a relatively lengthy seek operation.

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)