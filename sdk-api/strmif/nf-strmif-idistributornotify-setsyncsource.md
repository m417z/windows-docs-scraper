# IDistributorNotify::SetSyncSource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSyncSource` method is called when a new clock is registered.

## Parameters

### `pClock` [in]

Pointer to the new clock's [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) interface.

## Return value

Returns an **HRESULT** value.

## Remarks

This method is called before the filters are notified. Make sure to use **AddRef** on the *pClock* parameter if the plug-in distributor intends to hold it beyond this method call.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDistributorNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idistributornotify)