# IResourceConsumer::AcquireResource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AcquireResource` method notifies the resource consumer that a resource might be acquired.

## Parameters

### `idResource` [in]

Resource identifier of the resource to be acquired.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Consumer has successfully acquired the resource. |
| **S_FALSE** | Consumer has not acquired the resource but will use [IResourceManager::NotifyAcquire](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-notifyacquire) when it does. |
| **VFW_S_RESOURCE_NOT_NEEDED** | Consumer no longer needs the resource. |

The method may return some other error code, if the consumer fails to acquire the resource.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceConsumer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer)