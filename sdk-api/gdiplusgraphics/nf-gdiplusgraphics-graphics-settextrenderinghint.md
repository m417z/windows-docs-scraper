# Graphics::SetTextRenderingHint

## Description

The **Graphics::SetTextRenderingHint** method sets the text rendering mode of this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `newMode` [in]

Type: **[TextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint)**

Element of the [TextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint) enumeration that specifies the process currently used by this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to render text.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

[TextRenderingHintClearTypeGridFit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint) is supported only on Windows XP and Windows Server 2003.

You cannot use [TextRenderingHintClearTypeGridFit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint) along with CompositingModeSourceCopy.

#### Examples

The following example sets the text rendering hint to two different values and draws text to demonstrate each value.

```cpp
VOID Example_SetTextRenderingHint(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the text rendering hint to TextRenderingHintSingleBitPerPixel.
   graphics.SetTextRenderingHint(TextRenderingHintSingleBitPerPixel);

   // Draw text.
   graphics.DrawString(
   L"Low quality rendering",
       21,
   &Font(L"Arial", 24),
   PointF(0, 0),
   &SolidBrush(Color(255, 0, 0, 0)));

   // Get the text rendering hint.
   TextRenderingHint hint = graphics.GetTextRenderingHint();

   // Set the text rendering hint to TextRenderingHintAntiAlias.
   graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);

   // Draw more text to demonstrate the difference.
   graphics.DrawString(
   L"High quality rendering",
       22,
   &Font(L"Arial", 24),
   PointF(0, 50),
   &SolidBrush(Color(255, 0, 0, 0)));
}
```

## See also

[Antialiasing with Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-antialiasing-with-text-use)

[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettextrenderinghint)

[Graphics::SetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingmode)

[TextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint)