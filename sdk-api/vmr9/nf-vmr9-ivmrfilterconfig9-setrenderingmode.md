# IVMRFilterConfig9::SetRenderingMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRenderingMode` method sets the rendering mode used by the VMR.

## Parameters

### `Mode` [in]

Specifies the rendering mode as a [VMR9Mode](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9mode) value.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An invalid rendering mode was specified. |
| **VFW_E_WRONG_STATE** | The mode cannot be changed for some reason. See Remarks. |

## Remarks

The VMR is in windowed mode (**VMR9Mode_Windowed**) by default. Use this method to put the VMR into windowless mode (**VMR9Mode_Windowless**) or renderless mode (**VMR9Mode_Renderless**).

The mode cannot be changed after any pin has been connected. Also, the mode cannot be changed from windowless or renderless mode back to windowed mode, even before pins are connected. Therefore, specifying **VMR9Mode_Windowed** for the *Mode* parameter has no effect under any circumstances.

## See also

[IVMRFilterConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[VMR Modes of Operation](https://learn.microsoft.com/windows/desktop/DirectShow/vmr-modes-of-operation)