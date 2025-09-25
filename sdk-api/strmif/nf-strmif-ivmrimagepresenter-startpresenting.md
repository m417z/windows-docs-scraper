# IVMRImagePresenter::StartPresenting

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StartPresenting` method is called just before the video starts playing. The allocator-presenter should perform any necessary configuration in this method.

## Parameters

### `dwUserID` [in]

An application-defined **DWORD_PTR** cookie that uniquely identifies this instance of the VMR for use in scenarios when one instance of the allocator-presenter is used with multiple VMR instances.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

**PresentImage** can be called when the filter is in either a running or a paused state. `StartPresenting` and **StopPresenting** can be called only in a running state. Therefore, if the graph is paused before it is run, **PresentImage** will be called before `StartPresenting`.

## See also

[IVMRImagePresenter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenter)

[IVMRImagePresenter::StopPresenting](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagepresenter-stoppresenting)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)