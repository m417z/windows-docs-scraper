# TextureBrush::RotateTransform

## Description

The **TextureBrush::RotateTransform** method updates this texture brush's current transformation matrix with the product of itself and a rotation matrix.

## Parameters

### `angle` [in]

Type: **REAL**

Real number that specifies the angle, in degrees, of rotation.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the rotation matrix is on the left, and [MatrixOrderAppend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the rotation matrix is on the right. The default value is [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A single 3×3 matrix can store any sequence of affine transformations. If you have several 3×3 matrices, each of which represents an affine transformation, the product of those matrices is a single 3×3 matrix that represents the entire sequence of transformations. The transformation represented by that product is called a composite transformation. For example, suppose matrix R represents a rotation, and matrix T represents a translation. If matrix *M* is the product *RT*, then matrix *M* represents a composite transformation: first rotate, then translate.

The order of matrix multiplication is important. In general, the matrix product *RT* is not the same as the matrix product *TR*. In the example given in the previous paragraph, the composite transformation represented by *RT* (first rotate, then translate) is not the same as the composite transformation represented by *TR* (first translate, then rotate).

#### Examples

The following example creates a texture brush and sets the transformation of the brush. The code then uses the transformed brush to fill a rectangle.

```cpp
VOID Example_RotateTransform(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"HouseAndTree.Gif");
   TextureBrush textureBrush(&image);
   textureBrush.ScaleTransform(3, 1);                    // first scale
   textureBrush.RotateTransform(30, MatrixOrderAppend);  // then rotate
   graphics.FillRectangle(&textureBrush, 0, 0, 400, 200);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-scaletransform)

[TextureBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-settransform)

[TextureBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-translatetransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)