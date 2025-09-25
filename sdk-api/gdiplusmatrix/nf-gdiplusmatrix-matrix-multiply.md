# Matrix::Multiply

## Description

The **Matrix::Multiply** method updates this matrix with the product of itself and another matrix.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a matrix that will be multiplied by this matrix.

### `order` [in]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of the multiplication. MatrixOrderPrepend specifies that the passed matrix is on the left, and MatrixOrderAppend specifies that the passed matrix is on the right. The default value is MatrixOrderPrepend.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Matrix::Rotate](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-rotate)

[Matrix::RotateAt](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-rotateat)

[Matrix::Scale](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-scale)

[Matrix::Shear](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-shear)

[Matrix::Translate](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-translate)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)