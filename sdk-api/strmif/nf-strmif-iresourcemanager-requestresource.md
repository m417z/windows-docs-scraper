# IResourceManager::RequestResource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RequestResource` method requests the use of a given registered resource.

## Parameters

### `idResource` [in]

Resource token retrieved when the resource was registered.

### `pFocusObject` [in]

Pointer to the **IUnknown** interface of a focus object associated with a request (typically the **IUnknown** interface of the filter).

### `pConsumer` [in]

Pointer to the [IResourceConsumer](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer) interface on the object requesting the resource.

## Return value

Returns an **HRESULT** value. Returns S_OK if the requested resource is returned, or S_FALSE if the resource is not available, in which case the resource manager will call the requesting object back when the resource becomes available. Any other return is an error.

## Remarks

When there is more than one request for the resource, the resource manager will decide the priority by using the object of focus passed with each request and comparing it to the object of focus passed in the most recent [IResourceManager::SetFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-setfocus) method.

Requests will be filled in the following order of priority:

1. Requests made with exactly the same object of focus as the last [SetFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-setfocus) method.
2. Requests whose object of focus shares a common source filter whose object of focus shares a common filter graph.
3. Requests in the same process as the focus.

While checking this priority, the resource manager will use **QueryInterface** on the focus object for IID_IFilter. If found, the resource manager will use [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) methods to check the filter graph and look for common source filters with the current focus object.

A filter should pass the **IUnknown** interface of the filter in the *pFocusObject* parameter. The filter graph manager matches filters to the filter graph and will attempt to trace filters to common source filters when checking objects of focus.

The focus object must be valid for the entire lifetime of the request—until either the [IResourceManager::CancelRequest](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-cancelrequest) method is called, or the [IResourceManager::NotifyRelease](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-notifyrelease) method is called with the *bStillWant* parameter set to **FALSE**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourcemanager)