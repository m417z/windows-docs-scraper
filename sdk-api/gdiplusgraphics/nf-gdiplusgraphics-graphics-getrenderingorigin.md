# Graphics::GetRenderingOrigin

## Description

The **Graphics::GetRenderingOrigin** method gets the rendering origin currently set for this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The rendering origin is used to set the dither origin for 8-bits per pixel and 16-bits per pixel dithering and is also used to set the origin for hatch brushes.

## Parameters

### `x` [out]

Type: **INT***

Pointer to an
**INT** that receives the x-coordinate of the rendering origin.

### `y` [out]

Type: **INT***

Pointer to an
**INT** that receives the y-coordinate of the rendering origin.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::SetRenderingOrigin](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setrenderingorigin)