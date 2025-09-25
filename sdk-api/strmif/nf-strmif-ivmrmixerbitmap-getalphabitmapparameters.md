# IVMRMixerBitmap::GetAlphaBitmapParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAlphaBitmapParameters** method retrieves a copy of the current image and related blending parameters.

## Parameters

### `pBmpParms` [out]

A pointer to a [VMRALPHABITMAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmralphabitmap) structure that receives the bitmap, information about the blending values, and the location to blend it.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pBmpParms* is invalid. |
| **VFW_E_WRONG_STATE** | The mixer has not been loaded. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMixerBitmap Interface](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap)

[IVMRMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixerbitmap-setalphabitmap)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7)