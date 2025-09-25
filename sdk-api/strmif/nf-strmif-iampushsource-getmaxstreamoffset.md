# IAMPushSource::GetMaxStreamOffset

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMaxStreamOffset` method retrieves the maximum stream offset the filter can support.

## Parameters

### `prtMaxOffset` [out]

Pointer to a variable that receives a reference time indicating the maximum offset the filter can support.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The DirectShow implementation returns E_POINTER or S_OK.

## Remarks

If the stream offset is set to a value larger than the maximum supported offset, the filter is not guaranteed to have a buffer large enough to hold data for the entire amount of the offset. Unless there is another buffer downstream, data might be lost.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMPushSource Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iampushsource)