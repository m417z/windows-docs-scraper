# Matrix::Matrix(IN REAL,IN REAL,IN REAL,IN REAL,IN REAL,IN REAL)

## Description

Creates and initializes a **Matrix::Matrix** object based on six numbers that define an affine transformation.

## Parameters

### `m11` [in]

Type: **REAL**

Real number that specifies the element in the first row, first column—horizontal scaling component or cosine of rotation angle.

### `m12` [in]

Type: **REAL**

Real number that specifies the element in the first row, second column—horizontal shear component or sine of rotation angle.

### `m21` [in]

Type: **REAL**

Real number that specifies the element in the second row, first column—vertical shear component or negative sine of rotation angle.

### `m22` [in]

Type: **REAL**

Real number that specifies the element in the second row, second column—vertical scaling component or cosine of rotation angle.

### `dx` [in]

Type: **REAL**

Real number that specifies the element in the third row, first column—horizontal translation component.

### `dy` [in]

Type: **REAL**

Real number that specifies the element in the third row, second column—vertical translation component.

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Constructors](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-class-matrix-constructors)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)