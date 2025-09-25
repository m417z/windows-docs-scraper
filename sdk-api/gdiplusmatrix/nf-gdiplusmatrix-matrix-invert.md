# Matrix::Invert

## Description

If this matrix is invertible, the **Matrix::Invert** method replaces the elements of this matrix with the elements of its inverse.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If this matrix is not invertible, the method fails and returns InvalidParameter.

#### Examples

The following example passes the address of a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object to the
[SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settransform) method of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and then draws a rectangle. The rectangle is translated 30 units right and 20 units down by the world transformation of the
**Graphics** object. The code calls the **Matrix::Invert** method of the
**Matrix** object and sets the world transformation of the
**Graphics** object to the inverted matrix. The code draws a second rectangle that is translated 30 units left and 20 units up.

```cpp
VOID Example_Invert(HDC hdc)
{
   Graphics myGraphics(hdc);
   Pen myPen(Color(255, 0, 0, 255));

   Matrix matrix(1.0f, 0.0f, 0.0f, 1.0f, 30.0f, 20.0f);

   myGraphics.SetTransform(&matrix);
   myGraphics.DrawRectangle(&myPen, 0, 0, 200, 100);
   matrix.Invert();
   myGraphics.SetTransform(&matrix);
   myGraphics.DrawRectangle(&myPen, 0, 0, 200, 100);
}
```

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Matrix::IsInvertible](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-isinvertible)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)