# Graphics::SetCompositingMode

## Description

The **Graphics::SetCompositingMode** method sets the compositing mode of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `compositingMode` [in]

Type: **[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode)**

Element of the [CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode) enumeration that specifies the compositing mode.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Suppose you create a [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object based on a color that has an alpha component of 192, which is about 75 percent of 255. If your [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object has its compositing mode set to CompositingModeSourceOver, then areas filled with the solid brush are a blend that is 75 percent brush color and 25 percent background color. If your **Graphics** object has its compositing mode set to CompositingModeSourceCopy, then the background color is not blended with the brush color. However, the color rendered by the brush has an intensity that is 75 percent of what it would be if the alpha component were 255.

You cannot use CompositingModeSourceCopy along with TextRenderingHintClearTypeGridFit.

#### Examples

The following example creates a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and sets its compositing mode to CompositingModeSourceOver. The code creates a [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object based on a color that has an alpha component of 128. The code passes the address of that brush to the [Graphics::FillRectangle](https://learn.microsoft.com/previous-versions/ms535954(v=vs.85)) method of the **Graphics** object to fill a rectangle with a color that is a half-and-half blend of the brush color and the background color. Then the code sets the compositing mode of the **Graphics** object to CompositingModeSourceCopy and fills a second rectangle with the same brush. In that second rectangle, the brush color is not blended with the background color.

```cpp
VOID Example_SetCompositingMode(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object with an alpha-blended color.
   SolidBrush alphaBrush(Color(180, 255, 0, 0));

   // Set the compositing mode to CompositingModeSourceOver,
   // and fill a rectangle.
   graphics.SetCompositingMode(CompositingModeSourceOver);
   graphics.FillRectangle(&alphaBrush, 0, 0, 100, 100);

   // Set the compositing mode to CompositingModeSourceCopy,
   // and fill a rectangle.
   graphics.SetCompositingMode(CompositingModeSourceCopy);
   graphics.FillRectangle(&alphaBrush, 100, 0, 100, 100);
}
```

## See also

[Alpha Blending Lines and Fills](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-alpha-blending-lines-and-fills-use)

[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingmode)

[Graphics::GetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingquality)

[Graphics::SetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingquality)

[Graphics::SetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settextrenderinghint)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[New Features](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-new-features-about)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[TextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint)