# IAsyncReader::RequestAllocator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RequestAllocator` method requests an allocator during the pin connection.

## Parameters

### `pPreferred` [in]

Pointer to the [IMemAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator) interface on the input pin's preferred allocator, or **NULL**.

### `pProps` [in]

Specifies the address of an [ALLOCATOR_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-allocator_properties) structure, allocated by the caller. The caller should fill in any allocator properties that the input pin requires, and set the remaining members to zero.

### `ppActual` [out]

Address of a variable that receives an **IMemAllocator** interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure to initialize an allocator. |
| **VFW_E_BADALIGN** | An invalid alignment was specified. |
| **S_OK** | Allocator was returned. |

## Remarks

The downstream input pin should call this method during the connection process. If the pin has a preferred allocator, specify it in the *pPreferred* parameter. Specify any buffer requirements, such as buffer size or alignment, in the *pProps* parameter. The output pin chooses the allocator and returns a pointer to it in the *ppActual* parameter.

The output pin is not required to honor the input pin's requests. If the input pin has any absolute requirements, it should call the [IMemAllocator::GetProperties](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-getproperties) method on the returned allocator. It can fail the connect if the allocator properties are not suitable. Once the connection is established, the input pin must use the allocator chosen by the output pin.

The input pin is responsible for committing and decommitting the allocator.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)