# MFCreateVideoSampleAllocator callback function

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Creates an object that allocates video samples.

## Parameters

### `riid` [in]

The identifier of the interface to retrieve. Specify one of the following values:

| Value | Meaning |
| --- | --- |
| **IID_IUnknown** | Retrieve an **IUnknown** pointer. |
| **IID_IMFVideoSampleAllocator** | Retrieve an [IMFVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocator) pointer. |
| **IID_IMFVideoSampleAllocatorCallback** | Retrieve an [IMFVideoSampleAllocatorCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorcallback) pointer. |

### `ppSampleAllocator` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)