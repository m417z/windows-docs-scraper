# PathGradientBrush::MultiplyTransform

## Description

The **PathGradientBrush::MultiplyTransform** method updates the brush's transformation matrix with the product of itself and another matrix.

## Parameters

### `matrix` [in]

Type: **[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to the matrix that will be multiplied by the brush's current transformation matrix.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the passed matrix is on the left, and [MatrixOrderAppend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the passed matrix is on the right. The default value is [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder).

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
×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix R represents a rotation and matrix T represents a translation. If matrix M is the product RT, then matrix M represents a composite transformation: first rotate, then translate.

The order of matrix multiplication is important. In general, the matrix product RT is not the same as the matrix product TR. In the example given in the previous paragraph, the composite transformation represented by RT (first rotate, then translate) is not the same as the composite transformation represented by TR (first translate, then rotate).

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The code calls the [PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform) method of the
**PathGradientBrush** object to fill the brush's transformation matrix with the elements that represent a horizontal scaling by a factor of 3. Then the code calls the **PathGradientBrush::MultiplyTransform** method of that same
**PathGradientBrush** object to multiply the brush's existing transformation matrix by a matrix that represents a translation (10 right, 30 down). The MatrixOrderAppend argument indicates that the multiplication is performed with the translation matrix on the right.

After the multiplication, the brush's transformation matrix represents a composite transformation: first scale, then translate. That composite transformation is applied to the brush's boundary path during the call to
[FillRectangle](https://learn.microsoft.com/previous-versions/ms535957(v=vs.85)), so it is the area inside the transformed path that gets painted.

```cpp
VOID Example_MultiplyTransform(HDC hdc)
{
   Graphics graphics(hdc);
   Point pts[] = {Point(0, 0), Point(50, 0), Point(50, 50)};

   // Translate 10 right, 30 down.
   Matrix matrix(1.0f, 0.0f, 0.0f, 1.0f, 10.0f, 30.0f);

   PathGradientBrush pthGrBrush(pts, 3);
   pthGrBrush.ScaleTransform(3.0f, 1.0f);
   pthGrBrush.MultiplyTransform(&matrix, MatrixOrderAppend);

   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);
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

[PathGradientBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-resettransform)

[PathGradientBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-rotatetransform)

[PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform)

[PathGradientBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-settransform)

[PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)