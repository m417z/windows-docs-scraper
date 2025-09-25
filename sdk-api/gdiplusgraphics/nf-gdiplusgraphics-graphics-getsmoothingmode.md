# Graphics::GetSmoothingMode

## Description

The **Graphics::GetSmoothingMode** method determines whether smoothing (antialiasing) is applied to the
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **[SmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-smoothingmode)**

If smoothing (antialiasing) is applied to this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, this method returns SmoothingModeAntiAlias. If smoothing (antialiasing) is not applied to this
**Graphics** object, this method returns SmoothingModeNone. SmoothingModeAntiAlias and SmoothingModeNone are elements of the
[SmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-smoothingmode) enumeration.

## Remarks

To get the rendering quality level for text, use the
[Graphics::GetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettextrenderinghint) method.

#### Examples

The following example sets the smoothing mode to high speed and draws an ellipse. It then gets the smoothing mode, changes it to high quality, and draws a second ellipse to demonstrate the difference.

```cpp
VOID Example_GetSmoothingMode(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the smoothing mode to SmoothingModeHighSpeed.
   graphics.SetSmoothingMode(SmoothingModeHighSpeed);

   // Draw an ellipse.
   graphics.DrawEllipse(&Pen(Color(255, 0, 0, 0), 3), Rect(10, 0, 200, 100));

   // Get the smoothing mode.
   SmoothingMode mode = graphics.GetSmoothingMode();

   // Test mode to see whether smoothing has been set for the Graphics object.
   if (mode == SmoothingModeAntiAlias)
   {
   graphics.SetSmoothingMode(SmoothingModeHighQuality);
   }

   // Draw an ellipse to demonstrate the difference.
   graphics.DrawEllipse(&Pen(Color::Red, 3), Rect(220, 0, 200, 100));
}
```

## See also

[Antialiasing with Lines and Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-antialiasing-with-lines-and-curves-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)