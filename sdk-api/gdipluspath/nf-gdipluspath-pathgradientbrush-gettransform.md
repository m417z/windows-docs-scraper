# PathGradientBrush::GetTransform

## Description

The **PathGradientBrush::GetTransform** method gets transformation matrix of this path gradient brush.

## Parameters

### `matrix` [out]

Type: **[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that receives the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object maintains a transformation matrix that can store any affine transformation. When you use a path gradient brush to fill an area, GDI+ transforms the brush's boundary path according to the brush's transformation matrix and then fills the interior of the transformed path. The transformed path exists only during rendering; the boundary path stored in
**PathGradientBrush** object is not transformed.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an array of three points. The
[PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform) and
[PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform) methods set the elements of the brush's transformation matrix so that the matrix represents a composite transformation (first scale, then translate). That composite transformation applies to the brush's boundary path, so the call to
[FillRectangle](https://learn.microsoft.com/previous-versions/ms535957(v=vs.85)) fills the interior of a triangle that is the result of scaling and translating the boundary path. The code calls the **PathGradientBrush::GetTransform** method of the
**PathGradientBrush** object to obtain the brush's transformation matrix and then calls the
[GetElements](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-getelements) method of the retrieved [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object to fill an array with the matrix elements.

```cpp
VOID Example_GetTransform(HDC hdc)
{
  Graphics graphics(hdc);

   // Create a path gradient brush and set its transformation.
   Point pts[] = {Point(0, 0), Point(50, 0), Point(50, 50)};
   PathGradientBrush pthGrBrush(pts, 3);
   pthGrBrush.ScaleTransform(3.0f, 1.0f);
   pthGrBrush.TranslateTransform(10.0f, 30.0f, MatrixOrderAppend);

   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);

   // Obtain information about the path gradient brush.
   Matrix matrix;
   REAL elements[6];

   pthGrBrush.GetTransform(&matrix);
   matrix.GetElements(elements);

   for(INT j = 0; j <= 5; ++j)
   {
      // Inspect or use the value in elements[j].
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-settransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)