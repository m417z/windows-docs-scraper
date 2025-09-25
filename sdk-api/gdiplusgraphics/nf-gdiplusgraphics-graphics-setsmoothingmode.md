# Graphics::SetSmoothingMode

## Description

The **Graphics::SetSmoothingMode** method sets the rendering quality of the [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `smoothingMode` [in]

Type: **[SmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-smoothingmode)**

Element of the [SmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-smoothingmode) enumeration that specifies whether smoothing (antialiasing) is applied to lines and curves.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

To get the rendering quality for text, use the [Graphics::GetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettextrenderinghint) method. The higher the level of quality of the smoothing mode, the slower the performance.

#### Examples

The following example sets the smoothing mode to two different values and fills an ellipse to demonstrate each mode.

```cpp
VOID Example_SetSetSmoothingMode(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the smoothing mode to SmoothingModeHighSpeed, and fill an ellipse.
   graphics.SetSmoothingMode(SmoothingModeHighSpeed);
   graphics.FillEllipse(&SolidBrush(Color(255, 0, 0, 0)), 0, 0, 200, 100);

   // Set the smoothing mode to SmoothingModeHighQuality, and fill an ellipse.
   graphics.SetSmoothingMode(SmoothingModeHighQuality);
   graphics.FillEllipse(&SolidBrush(Color(255, 0, 0, 0)), 200, 0, 200, 100);
}
```

## See also

[Antialiasing with Lines and Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-antialiasing-with-lines-and-curves-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getsmoothingmode)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)