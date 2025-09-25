# VMR9AlphaBitmap structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9AlphaBitmap** structure is used with the [IVMRMixerBitmap9](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrmixerbitmap9) interface when an application provides a static bitmap for alpha blending with the video frame.

## Members

### `dwFlags`

Bitwise **OR** of flags from the [VMR9AlphaBitmapFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9alphabitmapflags) enumeration type.

### `hdc`

Handle to the GDI device context (HDC) for the bitmap. If this member contains a non-**NULL** value, set **pDDS** to **NULL** and set the **VMR9AlphaBitmap_hDC** flag in the **dwFlags** member. The device context is not compatible with GDI+.

### `pDDS`

Pointer to the **IDirect3DSurface9** interface of a Direct3D surface that contains the bitmap. If this member contains a valid pointer, set the **hdc** member to **NULL**. The surface format must be **D3DFMT_X8R8G8B8** (32-bit RGB) or **D3DFMT_A8R8G8B8** (32-bit RGB with per-pixel alpha). The surface must be allocated from the **D3DPOOL_SYSTEMMEM** pool.

### `rSrc`

Specifies the rectangle to copy from the source image. This rectangle is specified relative to the GDI device context or the DirectDraw surface.

When calling [IVMRMixerBitmap9::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixerbitmap9-setalphabitmap), the source rectangle must be valid if a GDI bitmap is specified in the **hdc** member. On the other hand, if a Direct3D surface is specified in the **pDDS** member, then you can either set **rSrc** to a valid rectangle, or use the entire surface by setting the VMR9AlphaBitmap_EntireDDS flag in **dwFlags**.

When calling [IVMRMixerBitmap9::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixerbitmap9-updatealphabitmapparameters), **rSrc** is always optional, and is used if **dwFlags** contains the VMR9AlphaBitmap_SrcRect flag.

### `rDest`

Specifies the destination rectangle in composition space.

### `fAlpha`

Specifies the alpha blending value; must be a value from 0.0 to 1.0 (inclusive).

### `clrSrcKey`

Specifies the source color key. This value is used if the **dwFlags** member contains the **VMR9AlphaBitmap_SrcColorKey**. A color key cannot be used with a Direct3D surface that contains per-pixel alpha.

### `dwFilterMode`

One of the following flags from the [VMR9MixerPrefs](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9mixerprefs) enumeration, or zero to specify no filtering.

| Value | Meaning |
| --- | --- |
| **MixerPref9_BiLinearFiltering**<br><br>0x00000010 | Bilinear interpolation filtering. |
| **MixerPref9_PointFiltering**<br><br>0x00000020 | Point filtering. |
| **MixerPref9_AnisotropicFiltering**<br><br>0x00000040 | Anisotropic filtering. |
| **MixerPref9_PyramidalQuadFiltering**<br><br>0x00000080 | Four-sample tent filtering. |
| **MixerPref9_GaussianQuadFiltering**<br><br>0x00000100 | Four-sample Gaussian filtering. |

This structure member is used only if the **dwFlags** member contains the **VMR9AlphaBitmap_FilterMode** flag.

Point filtering is particularly useful for images that contain text and do not need to be stretched prior to mixing.

## Remarks

To get the HDC for a GDI bitmap, do the following:

1. Call [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) to get the device context for the application's video window.
2. Call [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) to create a compatible device context.
3. Call [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) to select the bitmap into the device context obtained in the previous step.

When you are done, release the device context by calling [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)