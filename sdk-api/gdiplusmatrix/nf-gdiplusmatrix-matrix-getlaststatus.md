# Matrix::GetLastStatus

## Description

The **Matrix::GetLastStatus** method returns a value that indicates the nature of this
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The
**Matrix::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object have failed since the previous call to **Matrix::GetLastStatus**, then **Matrix::GetLastStatus** returns Ok.

If at least one method invoked on this
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object has failed since the previous call to **Matrix::GetLastStatus**, then **Matrix::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Matrix::GetLastStatus** immediately after constructing a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object to determine whether the constructor succeeded.

The first time you call the **Matrix::GetLastStatus** method of a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object, it returns Ok if the constructor succeeded and all methods invoked so far on the
**Matrix** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)