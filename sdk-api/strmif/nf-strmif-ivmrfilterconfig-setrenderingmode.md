# IVMRFilterConfig::SetRenderingMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRenderingMode` method sets the rendering mode used by the VMR.

## Parameters

### `Mode` [in]

Specifies the rendering mode as a [VMRMode](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrmode) value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An invalid rendering mode was specified. |
| **VFW_E_WRONG_STATE** | The mode cannot be changed for some reason. See Remarks. |

## Remarks

The VMR is in **VMRMode_Windowed** by default. Use this method only if you are putting the VMR into **VMRMode_Windowless** or **VMRMode_Renderless** mode. You cannot change the mode after any pin has been connected and you cannot change the mode from windowless or renderless back to windowed, even before any pins are connected. Therefore, specifying **VMRMode_Windowed** for *Mode* has no effect under any circumstances.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRFilterConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrfilterconfig)

[IVMRFilterConfig::GetRenderingMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-getrenderingmode)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)