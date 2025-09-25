# IStreamSample::CompletionStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves the status of the current sample's latest asynchronous update. If the update isn't complete, you can force it to complete.

## Parameters

### `dwFlags` [in]

Value that specifies whether to forcibly complete the update. This value is a combination of one or more of the following flags.

| Value | Description |
| --- | --- |
| COMPSTAT_NOUPDATEOK (0x01) | Force the update to complete as soon as possible, even if the sample update isn't yet complete. If the sample is updating and you didn't set the COMPSTAT_WAIT flag, the method returns MS_S_PENDING. If the sample is waiting to be updated, this method removes it from the queue and returns MS_S_NOTUPDATED. |
| COMPSTAT_WAIT (0x02) | Wait until the sample finishes updating before returning from this method. |
| COMPSTAT_ABORT (0x04) | Forces the update to complete, even if it's currently updating. This leaves the sample data in an undefined state. Combine this value with the COMPSTAT_WAITFORCOMPLETION flag to ensure that the update canceled. |

### `dwMilliseconds` [in]

If the *dwFlags* parameter is COMPSTAT_WAIT, this value is the number of milliseconds to wait for the update to complete. Specify INFINITE to indicate that you want to wait until the sample updates before this call returns.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The update aborted. |
| **MS_S_ENDOFSTREAM** | The sample wasn't updated because it reached the end of the stream. |
| **MS_S_NOUPDATE** | The update was forcibly completed; the sample was not updated by the stream. |
| **MS_S_PENDING** | An asynchronous update is pending. |
| **S_OK** | Success. |

## See also

[IStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample)