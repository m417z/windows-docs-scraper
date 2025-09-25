# IResourceManager::NotifyAcquire

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyAcquire` method notifies the resource manager that an attempt to acquire a resource has completed.

## Parameters

### `idResource` [in]

Token for the registered resource.

### `pConsumer` [in]

Pointer to the [IResourceConsumer](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer) interface of the object requesting the resource.

### `hr` [in]

Value indicating the success of the acquisition; S_OK if the resource was acquired, or an error value if not.

## Return value

Returns an **HRESULT** value that depends on the implementation. **HRESULT** can be one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Method isn't supported. |
| **S_OK or NOERROR** | Success. |

## Remarks

Use this method after an [IResourceConsumer::AcquireResource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourceconsumer-acquireresource) method returns an S_FALSE value, indicating that the acquisition will be asynchronous (that is, handled by a callback mechanism). If the *hr* parameter is S_OK, the resource manager will assume that the resource is now held by the caller. If the *hr* parameter is anything other than S_OK, the resource manager will assume that the attempt to acquire the resource failed and will reassign the resource elsewhere.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourcemanager)