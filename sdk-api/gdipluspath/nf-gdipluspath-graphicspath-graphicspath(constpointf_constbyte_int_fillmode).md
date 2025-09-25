# GraphicsPath::GraphicsPath(IN const PointF,IN const BYTE,IN INT,IN FillMode)

## Description

Creates a **GraphicsPath::GraphicsPath** object based on an array of points, an array of types, and a fill mode.

## Parameters

### `points` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of points that specifies the endpoints and control points of the lines and Bezier splines that are used to draw the path.

### `types` [in]

Type: **const BYTE***

Pointer to an array of bytes that holds the point type and a set of flags for each point in the
*points* array. The point type is stored in the three least significant bits, and the flags are stored in the four most significant bits. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array. This is the same as the number of elements in the
*types* array.

### `fillMode` [in]

Type: **[FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode)**

Optional. Element of the [FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode) enumeration that specifies how areas are filled if the path intersects itself. The default value is `FillModeAlternate`.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[FillMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fillmode)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath Constructors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-graphicspath(constgraphicspath_))

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)