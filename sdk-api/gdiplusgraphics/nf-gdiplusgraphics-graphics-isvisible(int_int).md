# IsVisible(INT,INT)

## Description

The **Graphics::IsVisible** method determines whether the specified point is inside the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.
The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Parameters

### `x`

Integer that specifies the x-coordinate of the point to test.

### `y`

Integer that specifies the y-coordinate of the point to test.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example tests whether the specified point is visible on the display device.
If it is, it fills an ellipse that represents that point.

```cpp
VOID Example_IsVisible5(HDC hdc)

{
   Graphics graphics(hdc);

   // Set up the coordinates of the point.
   int x = 100;
   int y = 100;

   // If the point (x, y) is visible, fill an ellipse that represents it.
   if (graphics.IsVisible(x, y))
   {
   graphics.FillEllipse(&SolidBrush(Color(255, 0, 0, 0)), x, y, 5, 5);
   }
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)