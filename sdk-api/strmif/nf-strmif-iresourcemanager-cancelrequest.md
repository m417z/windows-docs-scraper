# IResourceManager::CancelRequest

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CancelRequest` method cancels the request for a resource.

## Parameters

### `idResource` [in]

Resource identifier of a pending request.

### `pConsumer` [in]

Pointer to the [IResourceConsumer](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer) interface that made the request.

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

This method should be called when the [IResourceConsumer](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer) object that requested the resource has not received it and no longer requires it. If it has already received the resource, it should use the [IResourceManager::NotifyRelease](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-notifyrelease) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourcemanager)