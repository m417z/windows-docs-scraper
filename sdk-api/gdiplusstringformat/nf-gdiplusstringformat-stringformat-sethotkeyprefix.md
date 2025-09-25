# StringFormat::SetHotkeyPrefix

## Description

The **StringFormat::SetHotkeyPrefix** method sets the type of processing that is performed on a string when the hot key prefix, an ampersand (&), is encountered. The ampersand is called the hot key prefix and can be used to designate certain keys as hot keys.

## Parameters

### `hotkeyPrefix` [in]

Type: **[HotkeyPrefix](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hotkeyprefix)**

Element of the [HotkeyPrefix](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hotkeyprefix) enumeration that specifies how to process the hot key prefix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Hot keys, also called access keys, are keys that are programmed to provide an end user with keyboard shortcuts to functionality and are activated by pressing the ALT key. The keys are application dependent and are identified by an underscored letter, typically in a menu name or menu item; for example, when you press ALT, the letter F of the
**File** menu is underscored. The F key is a shortcut to display the
**File** menu.

A client programmer designates a hot key in an application by using the hot key prefix, an ampersand (&), in a string that typically is displayed as the name of a menu or an item in a menu and by using the
**StringFormat::SetHotkeyPrefix** method to set the appropriate type of processing. When a character in a string is preceded with an ampersand, the key that corresponds to the character becomes a hot key during the processing that occurs when the string is drawn on the display device. The ampersand is called a hot key prefix because it precedes the character to be activated. If HotkeyPrefixNone is passed to **StringFormat::SetHotkeyPrefix**, no processing of the hot key prefix occurs.

**Note** The term
*hot key* is used synonymously here with the term
*access key*. The term
*hot key* may have a different meaning in other Windows APIs.

#### Examples

The following example creates a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object and sets the type of hot key prefix processing to be performed on the string. The code then uses the
**StringFormat** object to draw a string that contains the hot key prefix character. The code also draws the string's layout rectangle.

```cpp
VOID Example_SetHotkeyPrefix(HDC hdc)
{
   Graphics graphics(hdc);

   SolidBrush  solidBrush(Color(255, 255, 0, 0));
   FontFamily  fontFamily(L"Times New Roman");
   Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);

   StringFormat stringFormat;
   stringFormat.SetHotkeyPrefix(HotkeyPrefixShow);

   graphics.DrawString(
      L"This &text has some &underlined characters.",
      43,  // string length
      &font,
      RectF(30, 30, 160, 200),
      &stringFormat,
      &solidBrush);

   // Draw the rectangle that encloses the text.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawRectangle(&pen, 30, 30, 160, 200);
}
```

## See also

[HotkeyPrefix](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hotkeyprefix)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormat::GetHotkeyPrefix](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-gethotkeyprefix)