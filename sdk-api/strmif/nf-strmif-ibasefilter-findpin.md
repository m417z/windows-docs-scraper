# IBaseFilter::FindPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FindPin` method retrieves the pin with the specified identifier.

## Parameters

### `Id` [in]

Pointer to a constant wide-character string that identifies the pin. Call the [IPin::QueryId](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryid) method to retrieve a pin's identifier.

### `ppPin` [out]

Address of a variable that receives a pointer to the pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface. If the method fails, **ppPin* is set to **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_FOUND** | Could not find a pin with this identifier. |

## Remarks

This method supports graph persistence. Use the [IPin::QueryId](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryid) method to save a pin's state, and use this method to restore the state. The pin's identifier string is defined by the filter implementation. The identifier must be unique within the filter.

If the method succeeds, the **IPin** interface that it returns has an outstanding reference count. Be sure to release the interface when you are done.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)