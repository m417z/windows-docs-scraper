# GraphicsPath::IsVisible(IN const Point &,IN const Graphics)

## Description

The **GraphicsPath::IsVisible** method determines whether a specified point lies in the area that is filled when this path is filled by a specified [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `point` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to the point to be tested.

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Optional. Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that specifies a world-to-device transformation. If the value of this parameter is **NULL**, the test is done in world coordinates; otherwise, the test is done in device coordinates. The default value is **NULL**.

## Return value

Type: **BOOL**

If the test point lies in the interior of this path, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[IsOutlineVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isoutlinevisible(inconstpoint__inconstpen_inconstgraphics))

[IsVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isvisible(inconstpoint__inconstgraphics))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)