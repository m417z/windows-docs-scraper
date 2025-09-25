# IBaseFilter::EnumPins

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EnumPins` method enumerates the pins on this filter.

## Parameters

### `ppEnum` [out]

Address of a variable that receives a pointer to the [IEnumPins](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumpins) interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_OUTOFMEMORY** | Insufficient memory |
| **E_POINTER** | **NULL** pointer argument |

## Remarks

This method returns an enumerator that supports the **IEnumPins** interface, which works like a standard COM enumerator. For more information, see [Enumerating Pins](https://learn.microsoft.com/windows/desktop/DirectShow/enumerating-pins).

If the method succeeds, the **IEnumPins** interface has an outstanding reference count. Be sure to release the interface when you are done.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)