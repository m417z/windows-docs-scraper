# GraphicsPath::IsOutlineVisible(IN const Point &,IN const Pen,IN const Graphics)

## Description

The **GraphicsPath::IsOutlineVisible** method determines whether a specified point touches the outline of this path when the path is drawn by a specified [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and a specified pen.

## Parameters

### `point` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to the point to be tested.

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object. This method determines whether the test point touches the path outline that would be drawn by this pen. More points will touch an outline drawn by a wide pen than will touch an outline drawn by a narrow pen.

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Optional. Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that specifies a world-to-device transformation. If the value of this parameter is **NULL**, the test is done in world coordinates; otherwise, the test is done in device coordinates. The default value is **NULL**.

## Return value

Type: **BOOL**

If the test point touches the outline of this path, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[IsOutlineVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isoutlinevisible(inconstpoint__inconstpen_inconstgraphics))

[IsVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isvisible(inconstpoint__inconstgraphics))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)