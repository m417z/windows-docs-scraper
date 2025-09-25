# IPin::EnumMediaTypes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **EnumMediaTypes** method enumerates the pin's preferred media types.

## Parameters

### `ppEnum` [out]

Receives a pointer to the [IEnumMediaTypes](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienummediatypes) interface. The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. Some pins do not enumerate media types unless the pin is connected to another filter. |

## Remarks

The [IEnumMediaTypes](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienummediatypes) interface works like a standard COM enumerator. For more information, see [Enumerating Objects in a Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/enumerating-objects-in-a-filter-graph). If the method succeeds, the **IEnumMediaTypes** interface has an outstanding reference count. Be sure to release it when you are done.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)