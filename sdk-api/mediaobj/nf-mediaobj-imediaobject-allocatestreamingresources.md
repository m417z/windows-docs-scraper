# IMediaObject::AllocateStreamingResources

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AllocateStreamingResources` method allocates any resources needed by the DMO. Calling this method is always optional.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

An application can call this method as a streaming optimization. It gives the DMO an opportunity to perform any time-consuming initializations before streaming begins. If you call this method, do so after you set the media types on the DMO, but before you make the first calls to **ProcessInput** or **ProcessOutput**.

This method is optional in the following sense:

* If the DMO does not support this method, the method returns S_OK.
* If the application never calls this method, the DMO allocates resources within a call to [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) or [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput).

If the DMO supports this method, it should also support the [IMediaObject::FreeStreamingResources](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-freestreamingresources) method.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)