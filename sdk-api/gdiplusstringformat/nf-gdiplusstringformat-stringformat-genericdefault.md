# StringFormat::GenericDefault

## Description

The **StringFormat::GenericDefault** method creates a generic, default
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object.

## Return value

Type: **[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)***

This method returns a pointer to the new
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object.

## Remarks

A generic, default
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object has the following characteristics:

* No string format flags are set.
* Character alignment and line alignment are set to StringAlignmentNear.
* Language ID is set to neutral language, which means that the current language associated with the calling thread is used.
* String digit substitution is set to StringDigitSubstituteUser.
* Hot key prefix is set to HotkeyPrefixNone.
* Number of tab stops is set to zero.
* String trimming is set to StringTrimmingCharacter.

#### Examples

The following example creates a generic, default
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object and then uses it to draw a formatted string. The code also draws the string's layout rectangle.

```cpp
VOID Example_GenericDefault(HDC hdc)
{
   Graphics graphics(hdc);

   SolidBrush  solidBrush(Color(255, 255, 0, 0));
   FontFamily  fontFamily(L"Times New Roman");
   Font        font(&fontFamily, 12, FontStyleRegular, UnitPoint);

   // Create a generic StringFormat object.
   const StringFormat* pStringFormat = StringFormat::GenericDefault();

   // Use the generic StringFormat object in a call to DrawString.
  graphics.DrawString(
      L"This text was formatted by a generic StringFormat object.",
      57,  // string length
      &font,
      RectF(30, 30, 100, 120),
      pStringFormat,
      &solidBrush);

   // Draw the rectangle that encloses the text.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawRectangle(&pen, 30, 30, 100, 120);
}
```

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[HotkeyPrefix](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hotkeyprefix)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[StringAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringalignment)

[StringDigitSubstitute](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringdigitsubstitute)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags)

[StringTrimming](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringtrimming)