# IVMRImagePresenter::PresentImage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PresentImage` method is called at precisely the moment this video frame should be presented.

## Parameters

### `dwUserID` [in]

An application-defined DWORD_PTR that uniquely identifies this instance of the VMR in scenarios when multiple instances of the VMR are being used with a single instance of an Allocator-Presenter. See Remarks

### `lpPresInfo` [in]

Specifies the [VMRPRESENTATIONINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrpresentationinfo) structure.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

`PresentImage` can be called when the filter is in either a running or a paused state. **StartPresenting** and **StopPresenting** can be called only in a running state. Therefore, if the graph is paused before it is run, `PresentImage` will be called before **StartPresenting**.

Applications can create custom blending effects by using a single instance of an Allocator-Presenter with multiple instances of the VMR either in a single filter graph or in multiple filter graphs. Using the allocator presenter in this way enables applications to blend streams from different filter graphs, or blend different streams within the same filter graph. If you are using a single instance of the VMR, set this value to zero.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRImagePresenter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenter)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)