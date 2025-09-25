# GraphicsPath::Widen

## Description

The **GraphicsPath::Widen** method replaces this path with curves that enclose the area that is filled when this path is drawn by a specified pen. The **GraphicsPath::Widen** method also flattens the path.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object. The path is made as wide as it would be when drawn by this pen.

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Optional. Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies a transformation to be applied along with the widening. If this parameter is **NULL**, no transformation is applied. The default value is **NULL**.

### `flatness` [in]

Type: **REAL**

Optional. Real number that specifies the maximum error between the path and its flattened approximation. Reducing the flatness increases the number of line segments in the approximation. The default value is FlatnessDefault, which is a constant defined in Gdiplusenums.h.

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

[GraphicsPath::Flatten](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-flatten)

[GraphicsPath::Outline](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-outline)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)