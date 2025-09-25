# GraphicsPath::Flatten

## Description

The **GraphicsPath::Flatten** method applies a transformation to this path and converts each curve in the path to a sequence of connected lines.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Optional. Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies the transformation to be applied to the path's data points. The default value is **NULL**, which specifies that no transformation is to be applied.

### `flatness` [in]

Type: **REAL**

Optional. Real number that specifies the maximum error between the path and its flattened approximation. Reducing the flatness increases the number of line segments in the approximation. The default value is `FlatnessDefault`, which is a constant defined in Gdiplusenums.h.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Flattening Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-flattening-paths-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)