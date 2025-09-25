# IVMRFilterConfig::SetImageCompositor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetImageCompositor` method installs an application-provided image compositor.

## Parameters

### `lpVMRImgCompositor` [in]

Pointer to the image compositor's [IVMRImageCompositor](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagecompositor) interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **VFW_E_WRONG_STATE** | The mixer is not currently loaded. |

## Remarks

Use this method to replace the VMR's default compositor with a custom compositor provided by the application. The image compositor is a sub-component of the mixer.

The compositor is automatically loaded when the VMR is in windowless or windowed mode. When the VMR is in renderless mode, the compositor must be loaded by calling [IVMRFilterConfig::SetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setnumberofstreams). The VMR manages all reference counting on the [IVMRImageCompositor](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagecompositor) interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRFilterConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrfilterconfig)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)