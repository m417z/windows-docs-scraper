# IMediaObject::FreeStreamingResources

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FreeStreamingResources` method frees resources allocated by the DMO. Calling this method is always optional.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

This method releases any resources that the [IMediaObject::AllocateStreamingResources](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-allocatestreamingresources) method initializes.

If the DMO does not support this method, the method returns S_OK. If you call this method during streaming, the method fails and the DMO does not release any resources.

Regardless of whether the method fails or succeeds, the application can continue to call other methods on the DMO. The DMO might need to re-initialize resources that were previously freed.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)