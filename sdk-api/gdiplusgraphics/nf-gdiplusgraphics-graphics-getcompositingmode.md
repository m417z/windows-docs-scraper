# Graphics::GetCompositingMode

## Description

The **Graphics::GetCompositingMode** method gets the compositing mode currently set for this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode)**

This method returns an element of the
[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode) enumeration that indicates the compositing mode currently set for this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Remarks

Suppose you create a [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object based on a color that has an alpha component of 192, which is about 75 percent of 255. If your
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object has its compositing mode set to CompositingModeSourceOver, then areas filled with the solid brush are a blend that is 75 percent brush color and 25 percent background color. If your
**Graphics** object has its compositing mode set to CompositingModeSourceCopy, then the background color is not blended with the brush color. However, the color rendered by the brush has an intensity that is 75 percent of what it would be if the alpha component were 255.

#### Examples

The following example creates a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and sets its compositing mode to CompositingModeSourceCopy. The code creates a [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object based on a color with an alpha component of 128. The code passes the address of that brush to the
[Graphics::FillRectangle](https://learn.microsoft.com/previous-versions/ms535957(v=vs.85)) method of the
**Graphics** object to fill a rectangle with a color that is not blended with the background color. The call to the **Graphics::GetCompositingMode** method of the
**Graphics** object demonstrates how to obtain the compositing mode (which is already known in this case). The code determines whether the compositing mode is CompositingModeSourceCopy and if so, changes it to CompositingModeSourceOver. Then the code calls
**Graphics::FillRectangle** a second time to fill a rectangle with a color that is a half-and-half blend of the brush color and the background color.

```cpp
VOID Example_GetCompositingMode(HDC hdc)
{
   Graphics graphics(hdc);

   graphics.SetCompositingMode(CompositingModeSourceCopy);
   SolidBrush alphaBrush(Color(128, 255, 0, 0));
   graphics.FillRectangle(&alphaBrush, 0, 0, 100, 100);

   // Get the compositing mode.
   CompositingMode compMode = graphics.GetCompositingMode();

   // Change the compositing mode if it is CompositingModeSourceCopy.
   if(compMode == CompositingModeSourceCopy)
   {
      graphics.SetCompositingMode(CompositingModeSourceOver);
   }

   graphics.FillRectangle(&alphaBrush, 0, 100, 100, 100);
}
```

## See also

[Alpha Blending Lines and Fills](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-alpha-blending-lines-and-fills-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingquality)

[Graphics::SetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingmode)

[Graphics::SetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingquality)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[New Features](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-new-features-about)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[Using Compositing Mode to Control Alpha Blending](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-compositing-mode-to-control-alpha-blending-use)