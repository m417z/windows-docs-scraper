# ColorMatrix structure

## Description

The **ColorMatrix** structure contains a 5×5 matrix of real numbers. Several methods of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) class adjust image colors by using a color matrix.

## Members

### `m`

Type: **REAL[5]**

5×5 array of real numbers.

## Remarks

A 5×5 color matrix is a homogeneous matrix for a 4-space transformation. The element in the fifth row and fifth column of a 5×5 homogeneous matrix must be 1, and all of the other elements in the fifth column must be 0. Color matrices are used to transform color vectors. The first four components of a color vector hold the red, green, blue, and alpha components (in that order) of a color. The fifth component of a color vector is always 1.

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)