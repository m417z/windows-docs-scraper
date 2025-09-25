# IAMDevMemoryControl::GetDevId

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryControl** interface is deprecated.

Retrieves the device ID of the on-board memory allocator.

## Parameters

### `pdwDevId` [out]

Pointer to the device ID.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method retrieves a unique ID that the hardware filter can use to verify that the specified allocator passed uses its on-board memory (because there can be more than one). The ID will be the same one as used to create the allocator object (using **CoCreateInstance**). For another filter to be able to use the on-board memory, it must have the same device ID as the on-board memory allocator.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemorycontrol)