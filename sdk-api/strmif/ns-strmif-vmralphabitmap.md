# VMRALPHABITMAP structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRALPHABITMAP** structure is used in the VMR-7 filter's [IVMRMixerBitmap](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap) methods when the application is providing a static alpha-blended bitmap to be displayed on the composited video frame.

## Members

### `dwFlags`

Flags that instruct the mixer where to find the bitmap. The following values are defined.

| Value | Meaning |
| --- | --- |
| **VMRBITMAP_DISABLE**<br><br>0x00000001 | Disable the bitmap. This flag cannot be combined with other flags. |
| **VMRBITMAP_HDC**<br><br>0x00000002 | Obtain the bitmap from the HDC. If this flag is set, the **hdc** member must specify a valid handle to a device context, and the **pDDS** member must be **NULL**.<br><br>If this flag is absent, the **pDDS** member must point to a valid DirectDraw surface, and the **hdc** member must be **NULL**. |
| **VMRBITMAP_ENTIREDDS**<br><br>0x00000004 | Take the entire DirectDraw surface. When this flag is specified, **rSrc** is ignored. This flag cannot be combined with the **VMRBITMAP_HDC** flag. |
| **VMRBITMAP_SRCCOLORKEY**<br><br>0x00000008 | The **clrSrcKey** value is valid and should be used when blending. |
| **VMRBITMAP_SRCRECT**<br><br>0x00000010 | Indicates that the **rSrc** rectangle is valid and specifies a sub-rectangle of the original app image to be blended. <br><br>This flag is only valid for the [IVMRMixerBitmap::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixerbitmap-updatealphabitmapparameters) method. For the [IVMRMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixerbitmap-setalphabitmap) method, the **rSrc** member must refer to the entire bitmap. |

### `hdc`

The handle to the device context for the bitmap. Specify **NULL** if the bitmap is located in a DirectDraw surface.

### `pDDS`

Pointer to a DirectDraw surface that contains the bitmap. Specify **NULL** if the bitmap is to be obtained from a GDI device context. If a DirectDraw surface is specified,
the pixel format must be ARGB-32 or RGB-32. If the surface contains per-pixel alpha, do not set the VMRBITMAP_SRCCOLORKEY flag in **dwFlags**.

### `rSrc`

Specifies the source rectangle in either the GDI device context or the DirectDraw surface.

### `rDest`

Specifies the destination rectangle in composition space.

### `fAlpha`

Specifies the alpha blending value; must be a value from 0.0 to 1.0 (inclusive).

### `clrSrcKey`

Specifies the source color key.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)