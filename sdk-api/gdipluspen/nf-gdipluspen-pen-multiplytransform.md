# Pen::MultiplyTransform

## Description

The **Pen::MultiplyTransform** method updates the world transformation matrix of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object with the product of itself and another matrix.

## Parameters

### `matrix` [in]

Type: **[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that is multiplied with the world transformation matrix of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. **MatrixOrderPrepend** specifies that the passed matrix is on the left, and **MatrixOrderAppend** specifies that the passed matrix is on the right. The default value is **MatrixOrderPrepend**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-gettransform)

[Pen::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-resettransform)

[Pen::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-rotatetransform)

[Pen::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-scaletransform)

[Pen::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-settransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)