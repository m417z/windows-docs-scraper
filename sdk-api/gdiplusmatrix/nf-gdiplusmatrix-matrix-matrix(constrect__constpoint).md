# Matrix::Matrix(IN const Rect &,IN const Point)

## Description

Creates a **Matrix::Matrix** object based on a rectangle and a point.

## Parameters

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object. The **X** data member of the rectangle specifies the matrix element in row 1, column 1. The **Y** data member of the rectangle specifies the matrix element in row 1, column 2. The **Width** data member of the rectangle specifies the matrix element in row 2, column 1. The **Height** data member of the rectangle specifies the matrix element in row 2, column 2.

### `dstplg` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to a [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object. The **X** data member of the point specifies the matrix element in row 3, column 1. The **Y** data member of the point specifies the matrix element in row 3, column 2.

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Constructors](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-class-matrix-constructors)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)