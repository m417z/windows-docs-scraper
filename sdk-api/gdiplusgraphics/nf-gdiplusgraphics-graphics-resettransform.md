# Graphics::ResetTransform

## Description

The **Graphics::ResetTransform** method sets the world transformation matrix of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to the identity matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The identity matrix represents a transformation that does nothing. If the world transformation matrix of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is the identity matrix, then no world transformation is applied to items drawn by that **Graphics** object.

#### Examples

The following example sets the world transformation of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a 45-degree rotation and then draws a rectangle. The code calls the **ResetTransform** method of the **Graphics** object and then draws a second rectangle. No rotation transformation is applied to the second rectangle.

```cpp
VOID Example_ResetTransform(HDC hdc)
{
   Graphics graphics(hdc);

   // Rotate the transformation and draw a rectangle.
   graphics.RotateTransform(45.0f);
   Pen blackPen(Color(255, 0, 0, 0));
   graphics.DrawRectangle(&blackPen, 100, 0, 100, 50);

   // Reset the transformation to identity, and draw a second rectangle.
   graphics.ResetTransform();
   Pen redPen(Color(255, 255, 0, 0));
   graphics.DrawRectangle(&redPen, 110, 0, 100, 50);
}
```

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettransform)

[Graphics::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-multiplytransform)

[Graphics::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-rotatetransform)

[Graphics::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-scaletransform)

[Graphics::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settransform)

[Graphics::TransformPoints](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-transformpoints(incoordinatespace_incoordinatespace_inoutpoint_inint))

[Graphics::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translatetransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)