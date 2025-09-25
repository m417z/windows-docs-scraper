# Graphics::IsVisibleClipEmpty

## Description

The **Graphics::IsVisibleClipEmpty** method determines whether the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty. The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Return value

Type: **BOOL**

If the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

If the visible clipping region of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty, there is no area left in which to draw. Consequently, nothing will be drawn when the visible clipping region is empty.

#### Examples

The following example determines whether the visible clipping region is empty. If it is not empty, it draws a rectangle.

```cpp
VOID Example_IsVisibleClipEmpty(HDC hdc)
{
   Graphics graphics(hdc);

   // If the clipping region is not empty, draw a rectangle.
   if (!graphics.IsVisibleClipEmpty())
   {
   graphics.DrawRectangle(&Pen(Color(255, 0, 0, 0), 3), 0, 0, 100, 100);
   }
}
```