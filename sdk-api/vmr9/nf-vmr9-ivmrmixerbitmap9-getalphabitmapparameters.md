# IVMRMixerBitmap9::GetAlphaBitmapParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAlphaBitmapParameters` method retrieves a copy of the current image and related blending parameters.

## Parameters

### `pBmpParms` [out]

Pointer to a [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure that receives the bitmap, information about the blending values, and the location to blend it.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pBmpParms* is invalid. |
| **VFW_E_WRONG_STATE** | The mixer has not been loaded. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerBitmap9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrmixerbitmap9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)