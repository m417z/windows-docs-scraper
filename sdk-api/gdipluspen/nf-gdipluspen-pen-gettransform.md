# Pen::GetTransform

## Description

The **Pen::GetTransform** method gets the world transformation matrix currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `matrix` [out]

Type: **[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that receives the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-multiplytransform)

[Pen::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-resettransform)

[Pen::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-rotatetransform)

[Pen::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-scaletransform)

[Pen::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-settransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)