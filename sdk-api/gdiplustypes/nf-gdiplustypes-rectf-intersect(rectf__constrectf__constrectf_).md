# RectF::Intersect(OUT RectF &,IN const RectF &,IN const RectF &)

## Description

The **RectF::Intersect** method determines the intersection of two rectangles and stores the result in a
[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object.

## Parameters

### `c` [out]

Type: **RectF&**

Reference to a
[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the intersection of the two rectangles.

### `a` [in]

Type: **const RectF&**

Reference to one of the two rectangles to be intersected.

### `b` [in]

Type: **const RectF&**

Reference to one of the two rectangles to be intersected.

## Return value

Type: **BOOL**

If the intersection of the two rectangles is not empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Intersect Methods](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-rectf-intersect(outrectf__inconstrectf__inconstrectf_))

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)