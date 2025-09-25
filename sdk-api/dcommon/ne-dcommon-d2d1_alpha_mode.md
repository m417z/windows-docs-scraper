# D2D1_ALPHA_MODE enumeration

## Description

Specifies how the alpha value of a bitmap or render target should be treated.

## Constants

### `D2D1_ALPHA_MODE_UNKNOWN:0`

The alpha value might not be meaningful.

### `D2D1_ALPHA_MODE_PREMULTIPLIED:1`

The alpha value has been premultiplied. Each color is first scaled by the alpha value. The alpha value itself is the same in both straight and premultiplied alpha. Typically, no color channel value is greater than the alpha channel value. If a color channel value in a premultiplied format is greater than the alpha channel, the standard source-over blending math results in an additive blend.

### `D2D1_ALPHA_MODE_STRAIGHT:2`

The alpha value has not been premultiplied. The alpha channel indicates the transparency of the color.

### `D2D1_ALPHA_MODE_IGNORE:3`

The alpha value is ignored.

### `D2D1_ALPHA_MODE_FORCE_DWORD:0xffffffff`

## Remarks

The **D2D1_ALPHA_MODE** enumeration is used with the [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format) enumeration to specify the alpha mode of a render target or bitmap. Different render targets and bitmaps support different alpha modes. For a list, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

### The Differences Between Straight and Premultiplied Alpha

When describing an RGBA color using straight alpha, the alpha value of the color is stored in the alpha channel. For example, to describe a red color that is 60% opaque, you'd use the following values: (255, 0, 0, 255 * 0.6) = (255, 0, 0, 153). The 255 value indicates full red, and 153 (which is 60 percent of 255) indicates that the color should have an opacity of 60 percent.

When describing an RGBA color using premultiplied alpha, each color is multiplied by the alpha value: (255 * 0.6, 0 * 0.6, 0 * 0.6, 255 * 0.6) = (153, 0, 0, 153).

Regardless of the alpha mode of the render target, [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f) values are always interpreted as straight alpha. For example, when specifying the color of an [ID2D1SolidColorBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1solidcolorbrush) for use with a bitmap that uses the premultiplied alpha mode, you'd specify the color just as you would if the bitmap used straight alpha. When you paint with the brush, Direct2D translates the color to the destination format for you.

### Alpha Mode for Render Targets

Regardless of the alpha mode setting, a render target's contents support transparency. For example, if you draw a partially transparent red rectangle with a render target with an alpha mode of **D2D1_ALPHA_MODE_IGNORE**, the rectangle will appear pink (if the background is white), as you might expect.

If you draw a partially transparent red rectangle when the alpha mode is [CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createcompatiblerendertarget(d2d1_size_f_d2d1_size_u_d2d1_pixel_format_d2d1_compatible_render_target_options_id2d1bitmaprendertarget).md) method) to create a bitmap that supports transparency.

### ClearType and Alpha Modes

If you specify an alpha mode other than **D2D1_ALPHA_MODE_IGNORE** for a render target, the text antialiasing mode automatically changes from [D2D1_TEXT_ANTIALIAS_MODE CLEARTYPE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_text_antialias_mode) to **D2D1_TEXT_ANTIALIAS_MODE GRAYSCALE**. (When you specify an alpha mode of **D2D1_ALPHA_MODE_UNKNOWN**, Direct2D sets the alpha for you depending on the type of render target. For a list of what the **D2D1_ALPHA_MODE_UNKNOWN** setting resolves to for each render target, see the [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes) overview.)

You can use the [SetTextAntialiasMode](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode) method to change the text antialias mode back to [D2D1_TEXT_ANTIALIAS_MODE CLEARTYPE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_text_antialias_mode), but rendering ClearType text to a transparent surface can create unpredictable results. If you want to render ClearType text to a transparent render target, we recommend that you use one of the following two techniques.

* Use the [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f_d2d1_antialias_mode)) method to clip the render target to the area where the text will be rendered, then call the [Clear](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-clear) method and specify an opaque color, then render your text.
* Use [DrawRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawrectangle(constd2d1_rect_f_id2d1brush_float_id2d1strokestyle)) to draw an opaque rectangle behind the area where the text will be rendered.

## See also

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes)