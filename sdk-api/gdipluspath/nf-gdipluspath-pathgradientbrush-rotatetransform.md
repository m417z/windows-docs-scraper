# PathGradientBrush::RotateTransform

## Description

The **PathGradientBrush::RotateTransform** method updates this brush's current transformation matrix with the product of itself and a rotation matrix.

## Parameters

### `angle` [in]

Type: **REAL**

Real number that specifies the angle of rotation in degrees.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the rotation matrix is on the left, and [MatrixOrderAppend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the rotation matrix is on the right. The default value is [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A single 3
×3 matrix can store any sequence of affine transformations. If you have several 3
×3 matrices, each of which represents an affine transformation, the product of those matrices is a single 3
×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix T represents a translation and matrix R represents a rotation. If matrix M is the product TR, then matrix M represents a composite transformation: first translate, then rotate.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The calls to the [PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform) and **PathGradientBrush::RotateTransform** methods of the
**PathGradientBrush** object set the elements of the brush's transformation matrix so that it represents a composite transformation: first scale, then rotate. The code uses the path gradient brush twice to paint a rectangle: once before the transformation is set and once after the transformation is set.

```cpp
VOID Example_RotateTransform(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path gradient brush based on an array of points.
   Point pts[] = {Point(0, 0), Point(50, 0), Point(50, 50)};
   PathGradientBrush pthGrBrush(pts, 3);

   // Fill an area with the path gradient brush (no transformation).
   graphics.FillRectangle(&pthGrBrush, 0, 0, 500, 500);

   pthGrBrush.ScaleTransform(3.0f, 1.0f);                 // first scale
   pthGrBrush.RotateTransform(60.0f, MatrixOrderAppend);  // then rotate

   // Fill the same area with the transformed path gradient brush.
   graphics.FillRectangle(&pthGrBrush, 0, 0, 500, 500);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-gettransform)

[PathGradientBrush::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-multiplytransform)

[PathGradientBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-resettransform)

[PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform)

[PathGradientBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-settransform)

[PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)