# PathGradientBrush::ScaleTransform

## Description

The **PathGradientBrush::ScaleTransform** method updates this brush's current transformation matrix with the product of itself and a scaling matrix.

## Parameters

### `sx` [in]

Type: **REAL**

Real number that specifies the horizontal scale factor.

### `sy` [in]

Type: **REAL**

Real number that specifies the vertical scale factor.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the scaling matrix is on the left, and [MatrixOrderAppend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the scaling matrix is on the right. The default value is [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder).

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
×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix T represents a translation and matrix S represents a scaling. If matrix M is the product TS, then matrix M represents a composite transformation: first translate, then scale.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The calls to the [PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform) and **PathGradientBrush::ScaleTransform** methods of the
**PathGradientBrush** object set the elements of the brush's transformation matrix so that it represents a composite transformation: first translate, then scale. The code uses the path gradient brush twice to paint a rectangle: once before the transformation is set and once after the transformation is set.

```cpp
VOID Example_ScaleTransform(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path gradient brush based on an array of points.
   Point pts[] = {Point(0, 0), Point(50, 0), Point(50, 50)};
   PathGradientBrush pthGrBrush(pts, 3);

   // Fill an area with the path gradient brush (no transformation).
   graphics.FillRectangle(&pthGrBrush, 0, 0, 500, 500);

   pthGrBrush.TranslateTransform(50.0f, 40.0f);               // translate
   pthGrBrush.ScaleTransform(3.0f, 2.0f, MatrixOrderAppend);  // then scale

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

[PathGradientBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-rotatetransform)

[PathGradientBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-settransform)

[PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)