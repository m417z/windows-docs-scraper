# IResourceConsumer::ReleaseResource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReleaseResource` method requests the resource consumer to release the specified resource.

## Parameters

### `idResource` [in]

Resource identifier to be released.

## Return value

Returns S_OK if the consumer has released it and requires it again when it becomes available, or S_FALSE if the consumer has not released it but will use [IResourceManager::NotifyRelease](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-notifyrelease) when it does.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceConsumer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourceconsumer)