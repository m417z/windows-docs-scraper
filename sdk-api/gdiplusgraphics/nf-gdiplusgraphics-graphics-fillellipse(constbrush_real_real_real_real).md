# Graphics::FillEllipse(IN const Brush,IN REAL,IN REAL,IN REAL,IN REAL)

## Description

The **Graphics::FillEllipse** method uses a brush to fill the interior of an ellipse that is specified by coordinates and dimensions.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a brush that is used to paint the interior of the ellipse.

### `x` [in]

Type: **REAL**

Real number that specifies the x-coordinate of the upper-left corner of the rectangle that specifies the boundaries of the ellipse.

### `y` [in]

Type: **REAL**

Real number that specifies the y-coordinate of the upper-left corner of the rectangle that specifies the boundaries of the ellipse.

### `width` [in]

Type: **REAL**

Real number that specifies the width of the rectangle that specifies the boundaries of the ellipse.

### `height` [in]

Type: **REAL**

Real number that specifies the height of the rectangle that specifies the boundaries of the ellipse.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)