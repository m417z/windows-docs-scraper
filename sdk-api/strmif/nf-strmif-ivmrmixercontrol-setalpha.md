# IVMRMixerControl::SetAlpha

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetAlpha` method sets a constant alpha value that is applied to this video stream.

## Parameters

### `dwStreamID` [in]

Specifies the input stream.

### `Alpha` [in]

Specifies the alpha blending value to be applied to all the pixels in this stream.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |

## Remarks

The alpha value specified can be between 0.0 (fully transparent) and 1.0 (full opaque).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMixerControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmixercontrol)

[IVMRMixerControl::GetAlpha](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixercontrol-getalpha)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)