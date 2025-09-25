# IResourceManager::NotifyRelease

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyRelease` method notifies the resource manager that [IResourceConsumer](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer) has released a resource.

## Parameters

### `idResource` [in]

Resource token.

### `pConsumer` [in]

Pointer to the object releasing the resource.

### `bStillWant` [in]

Flag that specifies whether the resource is still required. Set to **TRUE** to indicate that you still want the resource when it is next available, or **FALSE** if you no longer want the resource.

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

Use this method in response to an [IResourceConsumer::ReleaseResource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourceconsumer-releaseresource) method, or when you have finished using the resource.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourcemanager)