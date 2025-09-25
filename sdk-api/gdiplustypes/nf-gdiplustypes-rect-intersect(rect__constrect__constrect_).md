# Rect::Intersect(OUT Rect &,IN const Rect &,IN const Rect &)

## Description

The **Rect::Intersect** method determines the intersection of two rectangles and stores the result in a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object.

## Parameters

### `c` [out]

Type: **Rect&**

Reference to a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the intersection of the two rectangles.

### `a` [in]

Type: **const Rect&**

Reference to one of the two rectangles to be intersected.

### `b` [in]

Type: **const Rect&**

Reference to one of the two rectangles to be intersected.

## Return value

Type: **BOOL**

If the intersection of the two rectangles is not empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Intersect Methods](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-rect-intersect(outrect__inconstrect__inconstrect_))

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)