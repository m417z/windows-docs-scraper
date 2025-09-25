# IVMRFilterConfig9::SetImageCompositor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetImageCompositor` method installs an application-provided image compositor object.

## Parameters

### `lpVMRImgCompositor` [in]

Pointer to the image compositor object provided by the application.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Cannot change the compositor when the VMR filter's pins are connected. |
| **E_POINTER** | **NULL** pointer. |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The VMR is not in mixing mode. |

## Remarks

Use this method to replace the VMR's default compositor with a custom compositor provided by the application. The image compositor is a sub-component of the mixer. The mixer must be loaded, through a call to [IVMRFilterConfig9::SetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-setnumberofstreams),

before the compositor can be specified. The VMR manages all reference counting on the [IVMRImageCompositor9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagecompositor9) interface.

## See also

[IVMRFilterConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)