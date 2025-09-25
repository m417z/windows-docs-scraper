# Matrix::Reset

## Description

The **Matrix::Reset** method updates this matrix with the elements of the identity matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The elements on the main diagonal of the identity matrix are 1. All other elements of the identity matrix are 0.

#### Examples

The following example creates a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that represents a horizontal scaling by a factor of 5 and a vertical scaling by a factor of 3. The code calls the **Matrix::Reset** method to replace the elements of that matrix with the elements of the identity matrix. Then the code calls the
[Matrix::Translate](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-translate) method to update the matrix with the product of itself (the identity) and a translation matrix. The result is that the matrix represents only the translation, not the scaling. The code uses the matrix to set the world transformation of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and then draws a rectangle that is transformed according to that world transformation.

```cpp
VOID Example_Reset(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 255));

   Matrix matrix(5.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f);
   matrix.Reset();
   matrix.Translate(50.0f, 40.0f);

   graphics.SetTransform(&matrix);
   graphics.DrawRectangle(&pen, 0, 0, 100, 100);
}
```

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Matrix::IsIdentity](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-isidentity)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)