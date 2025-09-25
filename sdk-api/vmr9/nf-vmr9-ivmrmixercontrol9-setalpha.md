# IVMRMixerControl9::SetAlpha

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetAlpha` method sets a constant alpha value that is applied to this video stream.

## Parameters

### `dwStreamID` [in]

Specifies the input stream. This value corresponds to the input pin. For example, the first input pin is stream 0.

### `Alpha` [in]

Specifies the alpha blending value to be applied to all the pixels in this stream.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |

## Remarks

The alpha value specified can range from 0.0 (fully transparent) to 1.0 (full opaque).

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerControl9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmixercontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)