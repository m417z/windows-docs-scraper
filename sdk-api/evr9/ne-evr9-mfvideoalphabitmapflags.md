# MFVideoAlphaBitmapFlags enumeration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Defines flags for the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure.

## Constants

### `MFVideoAlphaBitmap_EntireDDS:0x1`

Alpha-blend the entire DirectDraw surface.

If you are alpha-blending a DirectDraw surface, you can set this flag when you call [IMFVideoMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap). If this flag is set, the mixer ignores the **rcSrc** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure. If this flag is absent, the **rcSrc** member specifies the source rectangle.

This flag cannot be used if you specify a GDI bitmap for alpha-blending. For a GDI bitmap, you must fill in the **rcSrc** member when you call [SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap).

This flag does not apply to the [IMFVideoMixerBitmap::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-updatealphabitmapparameters) method.

### `MFVideoAlphaBitmap_SrcColorKey:0x2`

If this flag is set, the **clrSrcKey** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure specifies a color key for alpha-blending. If this flag is absent, the **clrSrcKey** member is ignored.

This flag is not valid if you are alpha-blending a Direct3D surface with per-pixel alpha (D3DFMT_A8R8G8B8). When the DirectDraw surface has per-pixel alpha, the pixel alpha values are used for the alpha-blending operation.

### `MFVideoAlphaBitmap_SrcRect:0x4`

Update the source rectangle.

This flag applies to the [UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-updatealphabitmapparameters) method. If this flag is set, the **rcSrc** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure updates the source rectangle. If this flag is absent, the **rcSrc** member is ignored. By setting this flag, you can animate the image by selecting different portions of the bitmap.

This flag does not apply to the [SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap) method.

### `MFVideoAlphaBitmap_DestRect:0x8`

If this flag is set, the **nrcDest** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure specifies a normalized rectangle for scaling the bitmap. If this flag is absent, the **nrcDest** member is ignored.

### `MFVideoAlphaBitmap_FilterMode:0x10`

If this flag is set, the **dwFilterMode** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure specifies a Direct3D filtering mode. If this flag is absent, the **dwFilterMode** member is ignored.

### `MFVideoAlphaBitmap_Alpha:0x20`

If this flag is set, the **fAlpha** member of the [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure specifies an alpha value to apply to the entire image. If this flag is absent, the **fAlpha** member is ignored.

### `MFVideoAlphaBitmap_BitMask:0x3f`

Bitmask to validate flag values. This value is not a valid flag.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)