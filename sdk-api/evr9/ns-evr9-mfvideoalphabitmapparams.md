# MFVideoAlphaBitmapParams structure

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Specifies how the enhanced video renderer (EVR) alpha-blends a bitmap with the video.

## Members

### `dwFlags`

Bitwise OR of one or more flags from the [MFVideoAlphaBitmapFlags](https://learn.microsoft.com/windows/win32/api/evr9/ne-evr9-mfvideoalphabitmapflags) enumeration. These flags indicate which of the other structure members contain valid information.

### `clrSrcKey`

Source color key. This member is used if the **dwFlags** member contains the MFVideoAlphaBitmap_SrcColorKey flag. Any pixels in the bitmap that match the color key are rendered as transparent pixels.

You cannot specify a color key if you are alpha-blending a Direct3D surface with per-pixel alpha (D3DFMT_A8R8G8B8).

### `rcSrc`

Source rectangle. The source rectangle defines the region of the bitmap that is alpha-blended with the video. The source rectangle is given in pixels and is relative to the original bitmap.

If you are alpha-blending a GDI bitmap, you must fill in this structure when you call [IMFVideoMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap).

If you are alpha-blending a Direct3D surface and the **dwFlags** member contains the MFVideoAlphaBitmap_EntireDDS flag, the **rcSrc** member is ignored. If the flag is absent, you must fill in the **rcSrc** member.

After setting the initiali bitmap, you can update the source rectangle by calling [IMFVideoMixerBitmap::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-updatealphabitmapparameters). To update the source rectangle, set the MFVideoAlphaBitmap_SrcColorKey flag in the **dwFlags** member.

The source rectangle cannot be an empty rectangle, and cannot exceed the bounds of the bitmap.

### `nrcDest`

Destination rectangle. The destination rectangle defines the region of the composited video image that receives the alpha-blended bitmap. The destination rectangle is specified as a normalized rectangle using the [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure.

This member is used if the **dwFlags** member contains the MFVideoAlphaBitmap_DestRect flag. Otherwise, the default destination rectangle is {0, 0, 1, 1}.

### `fAlpha`

Alpha blending value. This member is used if the **dwFlags** member contains the MFVideoAlphaBitmap_Alpha flag. Otherwise, the default value is 1.0 (opaque). The valid range is 0.0 to 1.0, inclusive.

This value is applied to the entire bitmap image. To create transparent regions, use the **clrSrcKey** member or use a DirectDraw surface with per-pixel alpha.

### `dwFilterMode`

Direct3D filtering mode to use when performing the alpha-blend operation. Specify the filter mode as a D3DTEXTUREFILTERTYPE value. For more information, see the Direct3D documentation.

This member is used if the **dwFlags** member contains the MFVideoAlphaBitmap_FilterMode flag. Otherwise, the default value is D3DTEXF_POINT.

Point filtering is particularly useful for images that contain text and will not be stretched.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoMixerBitmap::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-updatealphabitmapparameters)

[MFVideoAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmap)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)