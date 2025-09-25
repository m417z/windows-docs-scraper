# Graphics::SetRenderingOrigin

## Description

The **Graphics::SetRenderingOrigin** method sets the rendering origin of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The rendering origin is used to set the dither origin for 8-bits-per-pixel and 16-bits-per-pixel dithering and is also used to set the origin for hatch brushes.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the rendering origin.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the rendering origin.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetRenderingOrigin](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getrenderingorigin)