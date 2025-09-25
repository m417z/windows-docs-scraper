# IVMRMixerControl9::GetOutputRect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOutputRect` method retrieves the position of this stream's video rectangle within the composition rectangle.

## Parameters

### `dwStreamID` [in]

Specifies the input stream. This value corresponds to the input pin. For example, the first input pin is stream 0.

### `pRect` [out]

Pointer to a [NORMALIZEDRECT](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-normalizedrect) structure that receives the destination rectangle in composition space.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pRect* is invalid. |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |

## Remarks

Because this rectangle exists in compositional space, there is no such thing as an "invalid" rectangle. For example, if left is greater than right, it means the video is mirrored in the x direction. An empty rectangle turns off this stream.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerControl9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmixercontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)