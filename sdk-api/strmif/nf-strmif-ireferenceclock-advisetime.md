# IReferenceClock::AdviseTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AdviseTime` method creates a one-shot advise request.

## Parameters

### `baseTime` [in]

Base reference time, in 100-nanosecond units. See Remarks.

### `streamTime` [in]

Stream offset time, in 100-nanosecond units. See Remarks.

### `hEvent` [in]

Handle to an event, created by the caller.

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

This method creates a one-shot advise request for the reference time *rtBaseTime* + *rtStreamTime*. The sum must be greater than zero and less than MAX_TIME, or the method returns E_INVALIDARG. At the requested time, the clock signals the event specified in the *hEvent* parameter.

To cancel the notification before the time is reached, call the [Unadvise](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ireferenceclock-unadvise) method and pass the *pdwAdviseToken* value returned from this call. After the notification has occurred, the clock automatically clears it, so it is not necessary to call **Unadvise**. However, it is not an error to do so.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IReferenceClock Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock)