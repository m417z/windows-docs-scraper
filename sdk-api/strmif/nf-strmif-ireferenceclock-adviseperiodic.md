# IReferenceClock::AdvisePeriodic

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AdvisePeriodic` method creates a periodic advise request.

## Parameters

### `startTime` [in]

Time of the first notification, in 100-nanosecond units. Must be greater than zero and less than MAX_TIME.

### `periodTime` [in]

Time between notifications, in 100-nanosecond units. Must be greater than zero.

### `hSemaphore` [in]

Handle to a semaphore, created by the caller.

### `pdwAdviseCookie` [out]

Pointer to a variable that receives an identifier for the advise request.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid time values. |
| **E_OUTOFMEMORY** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

At each notification time, the clock releases the semaphore specified in the *hSemaphore* parameter. When no further notifications are required, call [IReferenceClock::Unadvise](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ireferenceclock-unadvise) and pass the *pdwAdviseToken* value returned from this call.

The following code example creates an advise request that signals five seconds from the time it is created, and again every second thereafter:

| C++ |
| --- |
| ``` IReferenceClock *pRefClock = NULL; // Get an IReferenceClock pointer (not shown).<br><br>DWORD          dwAdviseToken; HANDLE         hSemaphore = CreateSemaphore(NULL, 0, 0x7FFFFFFF, NULL); REFERENCE_TIME rtPeriodTime = 10000000; // A one-second interval REFERENCE_TIME rtNow;<br><br>pRefClock->GetTime(&rtNow); pRefClock->AdvisePeriodic(rtNow + (5 * rtPeriodTime),                           rtPeriodTime,                            hSemaphore,                            &dwAdviseToken); ...<br><br>pRefClock->Unadvise(dwAdviseToken); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IReferenceClock Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock)