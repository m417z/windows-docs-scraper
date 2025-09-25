# IGraphBuilder::ShouldOperationContinue

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ShouldOperationContinue` method queries whether the current operation should continue. A filter that is performing some operation at the request of the graph can call this method to determine whether it should continue. Applications will not normally call this method.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The current operation should continue. |
| **S_FALSE** | The current operation should not continue. |
| **E_UNEXPECTED** | Unexpected error. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)