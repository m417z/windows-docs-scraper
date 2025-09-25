# IMixerPinConfig::SetColorKey

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetColorKey` method sets the color key being used by a video stream.

## Parameters

### `pColorKey` [in]

Pointer to a [COLORKEY](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-colorkey) structure.

## Return value

Returns an `HRESULT` value.

## Remarks

The term *color key* has different meanings depending on which stream it is referring to. The color key of the primary stream refers to the destination color key being used by the overlay surface. The color key of the secondary stream refers to the source color key used, when blitting from an offscreen surface to the primary surface.

Applications should set the color key of the primary pin to an obscure color (some color which, in all probability, will not be present on the desktop). Overlay mixer filters will try to pick an obscure color, but if the application knows that the specified color is part of some other content, then the application should change it.

Setting the color key on the secondary stream can be used to make the stream transparent and enable nonrectangular images. For example, if the secondary stream is closed-captioned text, then the closed-captioned text decoder should paint a solid color in the background and then set the color key on the corresponding pin to that color. This ensures that all pixels are transferred except those specified by the color key. If possible, applications should set the color key of the secondary stream to the same as that of the primary stream to give a slight performance advantage.

Setting this value on the primary stream sets the destination color key being used by the overlay surface. By default, the destination color key is used as the color key for all transparent (secondary) streams.

Valid arguments for the *pColorKey* parameter include CK_INDEX when video display mode is set to 256 colors, and CK_RGB when video display mode is set to a higher color depth such as hi-color, 24-bit, or 32-bit. The CK_RGB flag must be specified along with the CK_INDEX. If CK_INDEX flag is set then the index will be used as palette index in 256 color mode. But you must provide a **COLORREF** with a valid true color so that if the display mode is changed on the fly, DirectShow can switch to using the specified true color. This is because a number of true colors can be mapped to a single palette index, but going the other way from the palette index to a true color is not one-to-one.

**Note** Currently, this method is implemented only for the primary input pin.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::GetColorKey](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getcolorkey)