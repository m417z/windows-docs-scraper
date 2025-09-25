# Pen::ResetTransform

## Description

The **Pen::ResetTransform** method sets the world transformation matrix of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to the identity matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
**Ok** enumeration.

## Remarks

The identity matrix represents a transformation that does nothing. If the world transformation matrix of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object is the identity matrix, then no world transformation is applied to items drawn using that
**Pen** object.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets a scaling matrix to the pen, and draws a rectangle. The code then resets the transformation of the pen and draws a second rectangle.

```cpp
VOID Example_ResetTrans(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a pen, and set its transformation.
   Pen pen(Color(255, 0, 0, 255), 2);
   pen.ScaleTransform(8, 4);

   // Draw a rectangle with the transformed pen.
   graphics.DrawRectangle(&pen, 50, 50, 150, 100);

   pen.ResetTransform();

   // Draw a rectangle with no pen transformation.
   graphics.DrawRectangle(&pen, 250, 50, 150, 100);
}
```

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-gettransform)

[Pen::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-multiplytransform)

[Pen::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-rotatetransform)

[Pen::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-scaletransform)

[Pen::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-settransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)