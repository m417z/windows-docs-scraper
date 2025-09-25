# Graphics::FillRectangle(IN const Brush,IN INT,IN INT,IN INT,IN INT)

## Description

The **Graphics::FillRectangle** method uses a brush to fill the interior of a rectangle.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) that is used to paint the interior of the rectangle.

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the rectangle to be filled.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the rectangle to be filled.

### `width` [in]

Type: **INT**

Integer that specifies the width of the rectangle to be filled.

### `height` [in]

Type: **INT**

Integer that specifies the height of the rectangle to be filled.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)