# IMemInputPin::GetAllocatorRequirements

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAllocatorRequirements` method retrieves the allocator properties requested by the input pin.

## Parameters

### `pProps` [out]

Pointer to an [ALLOCATOR_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-allocator_properties), structure which is filled in with the requirements.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_NOTIMPL** | Not implemented |
| **E_POINTER** | **NULL** pointer argument |

## Remarks

When an output pin initializes a memory allocator, it can call this method to determine whether the input pin has any buffer requirements. The input pin is not required to implement this method. If the filter has specific alignment or prefix requirements, it should implement this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)