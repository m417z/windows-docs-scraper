# Matrix::Matrix(IN const RectF &,IN const PointF)

## Description

Creates a **Matrix::Matrix** object based on a rectangle and a point.

## Parameters

### `rect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object. The **X** data member of the rectangle specifies the matrix element in row 1, column 1. The **Y** data member of the rectangle specifies the matrix element in row 1, column 2. The **Width** data member of the rectangle specifies the matrix element in row 2, column 1. The **Height** data member of the rectangle specifies the matrix element in row 2, column 2.

### `dstplg` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object. The **X** data member of the point specifies the matrix element in row 3, column 1. The **Y** data member of the point specifies the matrix element in row 3, column 2.

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Constructors](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-class-matrix-constructors)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)