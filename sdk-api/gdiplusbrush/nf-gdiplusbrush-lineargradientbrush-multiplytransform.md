# LinearGradientBrush::MultiplyTransform

## Description

The **LinearGradientBrush::MultiplyTransform** method updates this brush's transformation matrix with the product of itself and another matrix.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a matrix to be multiplied by the brush's current transformation matrix.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. MatrixOrderPrepend specifies that the passed matrix is on the left, and MatrixOrderAppend specifies that the passed matrix is on the right. The default value is MatrixOrderPrepend.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A single 3
×3 matrix can store any sequence of affine transformations. If you have several 3
×3 matrices, each of which represents an affine transformation, the product of those matrices is a single 3
×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix R represents a rotation, and matrix T represents a translation. If matrix M is the product RT, then matrix M represents a composite transformation: first rotate, then translate.

The order of matrix multiplication is important. In general, the matrix product RT is not the same as the matrix product TR. In the example given in the previous paragraph, the composite transformation represented by RT (first rotate, then translate) is not the same as the composite transformation represented by TR (first translate, then rotate).

#### Examples

The following example creates a linear gradient brush and uses it to fill a rectangle. Next, the code sets the brush's transformation matrix, fills a rectangle with the transformed brush, modifies the brush's transformation matrix, and again fills a rectangle with the transformed brush.

```cpp
VOID Example_MultTrans(HDC hdc)
{
   Graphics myGraphics(hdc);

   Matrix S(2, 0, 0, 1, 0, 0);   // horizontal doubling
   Matrix T(1, 0, 0, 1, 50, 0);  // horizontal translation of 50 units

   LinearGradientBrush linGrBrush(
      Rect(0, 0, 200, 100),
      Color(255, 255, 0, 0),     // red
      Color(255, 0, 0, 255),     // blue
      LinearGradientModeHorizontal);

   // Fill a large area with the gradient brush (no transformation).
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 800, 100);

   // Apply the scaling transformation.
   linGrBrush.SetTransform(&S);

   // Fill a large area with the scaled gradient brush.
   myGraphics.FillRectangle(&linGrBrush, 0, 150, 800, 100);

   // Form a composite transformation: first scale, then translate.
   linGrBrush.MultiplyTransform(&T, MatrixOrderAppend);

   // Fill a large area with the scaled and translated gradient brush.
   myGraphics.FillRectangle(&linGrBrush, 0, 300, 800, 100);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-rotatetransform)

[LinearGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-scaletransform)

[LinearGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-translatetransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)