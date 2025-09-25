# Matrix::SetElements

## Description

The **Matrix::SetElements** method sets the elements of this matrix.

## Parameters

### `m11` [in]

Type: **REAL**

Real number that specifies the element in the first row, first column.

### `m12` [in]

Type: **REAL**

Real number that specifies the element in the first row, second column.

### `m21` [in]

Type: **REAL**

Real number that specifies the element in the second row, first column.

### `m22` [in]

Type: **REAL**

Real number that specifies the element in the second row, second column.

### `dx` [in]

Type: **REAL**

Real number that specifies the element in the third row, first column.

### `dy` [in]

Type: **REAL**

Real number that specifies the element in the third row, second column.

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

[Matrix::GetElements](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-getelements)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)