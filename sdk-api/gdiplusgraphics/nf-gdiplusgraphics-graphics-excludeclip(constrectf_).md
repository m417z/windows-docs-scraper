# ExcludeClip(RectF&)

## Description

The **Graphics::ExcludeClip** method updates the clipping region to the portion of itself that does not intersect the specified rectangle.

## Parameters

### `rect`

Reference to a rectangle to use to update the clipping region.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example uses a rectangle to update a clipping region and then draws a rectangle that demonstrates the updated clipping region.

```cpp
VOID Example_ExcludeClip2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a RectF object, and set the clipping region to its exclusion.
   RectF excludeRect(100.0f, 100.0f, 200.0f, 200.0f);
   graphics.ExcludeClip(excludeRect);

   // Fill a rectangle to demonstrate the clipping region.
   graphics.FillRectangle(&SolidBrush((255, 0, 0, 255)), 0, 0, 600, 600);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)