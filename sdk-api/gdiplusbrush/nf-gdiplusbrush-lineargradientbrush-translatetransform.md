# LinearGradientBrush::TranslateTransform

## Description

The **LinearGradientBrush::TranslateTransform** method updates this brush's current transformation matrix with the product of itself and a translation matrix.

## Parameters

### `dx` [in]

Type: **REAL**

Real number that specifies the horizontal component of the translation.

### `dy` [in]

Type: **REAL**

Real number that specifies the vertical component of the translation.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. MatrixOrderPrepend specifies that the translation matrix is on the left, and MatrixOrderAppend specifies that the translation matrix is on the right. The default value is MatrixOrderPrepend.

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
×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix S represents a scaling, and matrix T represents a translation. If matrix M is the product ST, then matrix M represents a composite transformation: first scale, then translate.

The order of matrix multiplication is important. In general, the matrix product RT is not the same as the matrix product TR. In the example given in the previous paragraph, the composite transformation represented by RT (first rotate, then translate) is not the same as the composite transformation represented by TR (first translate, then rotate).

#### Examples

The following example creates a linear gradient brush and uses it to fill a rectangle. Next, the code modifies the brush's transformation matrix, applying a composite transformation, and then fills a rectangle with the transformed brush.

```cpp
VOID Example_TranslateTrans(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      Rect(0, 0, 80, 40),
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 0, 255),  // blue
      LinearGradientModeHorizontal);

   // Fill a large area with the linear gradient brush (no transformation).
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 800, 150);

   // Apply a composite transformation: first scale, then translate.
   linGrBrush.ScaleTransform(2, 1);                     // horizontal doubling
   linGrBrush.TranslateTransform(30, MatrixOrderAppend);// translation

   // Fill a large area with the transformed linear gradient brush.
   myGraphics.FillRectangle(&linGrBrush, 0, 200, 800, 150);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-multiplytransform)

[LinearGradientBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-resettransform)

[LinearGradientBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-rotatetransform)

[LinearGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-scaletransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)