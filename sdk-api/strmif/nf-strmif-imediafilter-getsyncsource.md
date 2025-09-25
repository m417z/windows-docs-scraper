# IMediaFilter::GetSyncSource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSyncSource` method retrieves the current reference clock.

## Parameters

### `pClock` [out]

Receives a pointer to the clock's [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) interface. The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_POINTER** | **NULL** pointer argument |

## Remarks

This method returns the same reference clock as the last call to [IMediaFilter::SetSyncSource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-setsyncsource). If there is no reference clock, *pClock* receives the value **NULL**. When the method returns, if **pClock* is non-**NULL**, the **IReferenceClock** interface has an outstanding reference count. Be sure to release it when you are done.

You can also call this method on the Filter Graph Manager to determine the current reference clock.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)