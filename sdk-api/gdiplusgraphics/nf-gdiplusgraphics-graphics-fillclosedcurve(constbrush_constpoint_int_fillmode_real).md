# Graphics::FillClosedCurve(IN const Brush,IN const Point,IN INT,IN FillMode,IN REAL)

## Description

The **Graphics::FillClosedCurve** method creates a closed cardinal spline from an array of points and uses a brush to fill, according to a specified mode, the interior of the spline.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the spline.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of points that this method uses to create a closed cardinal spline. Each point in the array is a point on the spline.

### `count` [in]

Type: **INT**

Integer that specifies the number of points in the
*points* array.

### `fillMode` [in]

Type: **[FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode)**

Element of the [FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode) enumeration that specifies how to fill a closed area that is created when the curve passes over itself.

### `tension` [in]

Type: **REAL**

Optional. Nonnegative real number that specifies how tightly the spline bends as it passes through the points. A value of 0 specifies that the spline is a sequence of straight lines. As the value increases, the curve becomes fuller. The default value is 0.5f.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cardinal-splines-about)

[Drawing Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-cardinal-splines-use)

[FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)