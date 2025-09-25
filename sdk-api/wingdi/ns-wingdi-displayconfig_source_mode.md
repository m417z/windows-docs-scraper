# DISPLAYCONFIG_SOURCE_MODE structure

## Description

The **DISPLAYCONFIG_SOURCE_MODE** structure represents a point or an offset in a two-dimensional space.

## Members

### `width`

The width in pixels of the source mode.

### `height`

The height in pixels of the source mode.

### `pixelFormat`

A value from the [DISPLAYCONFIG_PIXELFORMAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_pixelformat) enumeration that specifies the pixel format of the source mode.

### `position`

A [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the position in the desktop coordinate space of the upper-left corner of this source surface. The source surface that is located at (0, 0) is always the primary source surface.

## Remarks

The arrangement of source surfaces on the desktop is controlled by the **position** member, which specifies the position in desktop coordinates of the upper-left corner of the source surface. The source surface that is positioned at (0, 0) is considered the primary. GDI has strict rules about how the source surfaces can be arranged in the desktop space. For example, there cannot be any gaps between source surfaces, and there can be no overlaps.

The [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function attempts to rearrange source surfaces in order to enforce these layout rules. The caller must make every effort to lay out the source surfaces correctly because GDI rearranges the sources in an undefined manner to enforce the layout rules. The resultant layout may not be what the caller wanted to achieve.

## See also

[DISPLAYCONFIG_PIXELFORMAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_pixelformat)

[POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)