# Rect::IsEmptyArea

## Description

The **Rect::IsEmptyArea** method determines whether this rectangle is empty.

## Return value

Type: **BOOL**

If the rectangle is empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

A rectangle is defined as empty if either the width or the height is zero or less.

#### Examples

The following example creates a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object, inflates the dimensions of the rectangle, and determines whether the rectangle is empty.

```cpp
VOID Example_IsEmptyArea(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Rect object, and inflate the dimensions.
   Rect rect(50, 50, 200, 100);
   rect.Inflate(0, -120);

   // Determine whether the rectangle is empty.
   if(rect.IsEmptyArea())

   // The rectangle does not enclose any area.
}
```

## See also

[Inflate Methods](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-rect-inflate(inconstpoint_))

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)