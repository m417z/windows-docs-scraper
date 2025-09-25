# IVMRMixerBitmap::SetAlphaBitmap

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAlphaBitmap** method specifies a new bitmap image and the source location of the bitmap and how and where it should be rendered on the destination rectangle.

## Parameters

### `pBmpParms` [in]

A pointer to a [VMRALPHABITMAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmralphabitmap) structure that contains information about the bitmap.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pBmpParms* is **NULL**. |
| **E_INVALIDARG** | Invalid argument. See Remarks. |
| **E_OUTOFMEMORY** | Could not create a destination DC or DIBSection for the bitmap. |
| **E_FAIL** | BitBlt to bitmap surface failed. |

## Remarks

To remove the bitmap, set the [VMRALPHABITMAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmralphabitmap) structure and call **SetAlphaBitmap** again.

The method might return **E_INVALIDARG** for several reasons:

[VMRALPHABITMAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmralphabitmap) structure contains an invalid combination of flags.
[VMRALPHABITMAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmralphabitmap) structure does not specify a valid HDC or DirectDraw surface.* The value of **fAlpha** is invalid.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMixerBitmap Interface](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap)

[IVMRMixerBitmap::GetAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixerbitmap-getalphabitmapparameters)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7)