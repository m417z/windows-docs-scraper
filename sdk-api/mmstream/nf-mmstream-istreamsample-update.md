# IStreamSample::Update

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Performs a synchronous or an asynchronous update on the current sample.

## Parameters

### `dwFlags` [in]

Flag that specifies whether the update is synchronous or asynchronous. The SSUPDATE_ASYNC flag specifies an asynchronous update, which you can set if both *hEvent* and *pfnAPC* are **NULL**. Use SSUPDATE_CONTINUOUS to continuously update the sample until you call the [IStreamSample::CompletionStatus](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-istreamsample-completionstatus) method.

### `hEvent` [in]

Handle to an event that this method will trigger when the update is complete.

### `pfnAPC` [in]

Pointer to a Win32 asynchronous procedure call (APC) function that this method will call after it completes the sample update.

### `dwAPCData` [in]

Value that this method passes to the function specified by the *pfnAPC* parameter.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The update aborted. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_POINTER** | One of the parameters is invalid. |
| **MS_E_BUSY** | This sample already has a pending update. |
| **MS_S_ENDOFSTREAM** | Reached the end of the stream; the sample wasn't updated. |
| **MS_S_PENDING** | The asynchronous update is pending. |
| **S_OK** | Success. |
| **VFW_E_NOT_COMMITTED** | Cannot allocate a sample because the allocator is not committed. |

## Remarks

This method can be used to perform a synchronous or asynchronous update of a sample. If both *hEvent* and *pfnAPC* are **NULL** then the update will be synchronous unless either of the SSUPDATE_ASYNC or SSUPDATE_CONTINUOUS flags is specified. When a synchronous update returns, the result of the function contains the I/O completion status.

You can't specify values for both *hEvent* and *pfnAPC*; the method will fail.

Asynchronous updates might complete before the update returns; in that case, the return value is S_OK. If you specify an event and the update returns S_OK, this method sets the event on return. If you specify an APC function and the update returns S_OK, the APC will not be queued and the function will not be called.

Asynchronous updates that don't complete prior to returning will return a value of MS_S_PENDING.

If an application creates multiple streams, it must perform an asynchronous update on each stream. Call **WaitForMultipleObjects** to wait for each stream update to complete, before making the next update. Otherwise, the application might block.

## See also

[IStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample)