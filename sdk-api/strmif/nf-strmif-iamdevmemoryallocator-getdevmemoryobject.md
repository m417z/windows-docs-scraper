# IAMDevMemoryAllocator::GetDevMemoryObject

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryAllocator** interface is deprecated.

Retrieves an **IUnknown** interface pointer to a device memory control object that can be aggregated with a custom allocator.

## Parameters

### `ppUnkInnner` [out]

Address of a pointer to the newly created control object's own **IUnknown**. This inner **IUnknown** interface should be released when the outer object is destroyed. The custom allocator should call the **QueryInterface** method on this pointer to obtain the [IAMDevMemoryControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemorycontrol) interface.

### `pUnkOuter` [in]

Pointer to the custom allocator's own **IUnknown** interface. This interface aggregates the device memory control object inside the custom allocator.

## Return value

Returns an **HRESULT** value.

## Remarks

The device memory control object is necessary to aggregate with the custom allocator, because renderers that require the use of on-board memory will query for [IAMDevMemoryControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemorycontrol) when they receive a new allocator, to verify that the memory is from the same device. This occurs because the hardware filter will receive an [IMemAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator) object, which might or might not use the on-board memory. To decide if it is a compatible allocator, the object would query for the **IAMDevMemoryControl** interface to access specific methods. The **IAMDevMemoryControl** creates an aggregated object that implements the methods of **IAMDevMemoryControl** (these are often hardware-specific).

See COM documentation for rules on how the outer object implements aggregation.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator)