# IMemInputPin::GetAllocator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAllocator` method retrieves the memory allocator proposed by this pin. After the allocator has been selected, this method returns a pointer to the selected allocator.

## Parameters

### `ppAllocator` [out]

Receives a pointer to the allocator's [IMemAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator) interface. The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NO_ALLOCATOR** | No allocator is available. |

## Remarks

When an output pin connects to an input pin, it negotiates with the input pin to decide on a memory allocator. The output pin calls this method to retrieve the input pin's proposed allocator. It calls the [IMemInputPin::NotifyAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-notifyallocator) method to specify which allocator it selected.

If this method succeeds, the **IMemAllocator** interface has an outstanding reference count. Be sure to release it when you are done.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)