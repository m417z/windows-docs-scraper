# IVMRImagePresenter9::StartPresenting

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StartPresenting` method is called just before the video starts playing. The allocator-presenter should perform any necessary configuration in this method.

## Parameters

### `dwUserID` [in]

An application-defined **DWORD_PTR** cookie that uniquely identifies this instance of the VMR for use in scenarios when one instance of the allocator-presenter is used with multiple VMR instances.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**PresentImage** can be called when the filter is in either a running or a paused state. `StartPresenting` and **StopPresenting** can be called only in a running state. Therefore, if the graph is paused before it is run, **PresentImage** will be called before `StartPresenting`.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRImagePresenter9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenter9)

[StopPresenting](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrimagepresenter9-stoppresenting)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)