# Rect::Union

## Description

The **Rect::Union** method determines the union of two rectangles and stores the result in a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object.

## Parameters

### `c` [out]

Type: **Rect&**

Reference to a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the union of the two rectangles.

### `a` [in]

Type: **const Rect&**

Reference to one of the two rectangles used to form the union.

### `b` [in]

Type: **const Rect&**

Reference to one of the two rectangles used to form the union.

## Return value

Type: **BOOL**

If the union of two rectangles is not empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

In Windows GDI+, the union of two rectangles is the smallest rectangle that encloses the two rectangles. A rectangle is defined as empty if its width or height is less than or equal to zero.

#### Examples

The following example creates three rectangles. The code forms the union of the first two rectangles and stores the result in the third rectangle. The code determines whether the union is nonempty and, if so, draws the union.

```cpp
VOID Example_UnionABC(HDC hdc)
{
   Graphics graphics(hdc);
   Pen* pGreenPen;

   // Create three Rect objects.
   Rect rectA(50, 50, 200, 100);
   Rect rectB(70, 20, 100, 200);
   Rect rectC;

   // Determine the union of rectA and rectB, and store the result in rectC.
   if(rectC.Union(rectC, rectA, rectB))
   {
      // rectC is not empty.
      // Draw the union with a thick green pen.
      pGreenPen = new Pen(Color(255, 0, 255, 0), 7);
      graphics.DrawRectangle(pGreenPen, rectC);
      delete pGreenPen;
   }
   // Draw rectA and rectB with a thin black pen.
   Pen blackPen(Color(255, 0, 0, 0), 1);
   graphics.DrawRectangle(&blackPen, rectA);
   graphics.DrawRectangle(&blackPen, rectB);
}
```

## See also

[Intersect Methods](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-rect-intersect(outrect__inconstrect__inconstrect_))

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)