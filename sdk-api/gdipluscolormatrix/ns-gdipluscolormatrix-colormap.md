# ColorMap structure

## Description

The **ColorMap** structure contains two [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects. Several methods of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) class adjust image colors by using a color remap table, which is an array of **ColorMap** structures.

## Members

### `oldColor`

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

The original color.

### `newColor`

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

The new color.

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Using a Color Remap Table](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-color-remap-table-use)