# Rect::Equals

## Description

The **Rect::Equals** method determines whether two rectangles are the same.

## Parameters

### `rect` [in]

Type: **const Rect&**

Reference to a rectangle to compare to this rectangle.

## Return value

Type: **BOOL**

If the rectangles are the same, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

Two rectangles are the same if their
**X**,
**Y**,
**Width**, and
**Height** data members are the same.

#### Examples

The following example creates two
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) objects, moves the second
**Rect** object horizontally by a specified value, and then determines whether the two
**Rect** objects are the same.

```cpp
Rect rect1(50, 50, 200, 100);
Rect rect2(20, 50, 200, 100);

rect2.Offset(30, 0);

if(rect2.Equals(rect1))
{
   // The two rectangles are the same.
}
```

## See also

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)