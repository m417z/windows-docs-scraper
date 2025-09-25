# StringFormat::SetTabStops

## Description

The **StringFormat::SetTabStops** method sets the offsets for tab stops in this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object.

## Parameters

### `firstTabOffset` [in]

Type: **REAL**

Real number that specifies the initial offset position. This initial offset position is relative to the string's origin and the offset of the first tab stop is relative to the initial offset position.

### `count` [in]

Type: **INT**

Integer that specifies the number of tab-stop offsets in the
*tabStops* array.

### `tabStops` [in]

Type: **const REAL***

Pointer to an array of real numbers that specify the tab-stop offsets. The offset of the first tab stop is the first value in the array, the offset of the second tab stop, the second value in the array, and so on.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Each tab-stop offset in the
*tabStops* array, except the first one, is relative to the previous one. The first tab-stop offset is relative to the initial offset position specified by
*firstTabOffset*. For example, if the initial offset position is 8 and the first tab-stop offset is 50, then the first tab stop is at position 58. If the initial offset position is zero, then the first tab-stop offset is relative to position 0, the string origin.

#### Examples

The following example creates a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object, sets tab stops, and uses the
**StringFormat** object to draw a string that contains tab characters (\t). The code also draws the string's layout rectangle.

```cpp
VOID Example_SetTabStops(HDC hdc)
{
   Graphics graphics(hdc);

   REAL         tabs[] = {150, 100, 100};
   FontFamily   fontFamily(L"Courier New");
   Font         font(&fontFamily, 12, FontStyleRegular, UnitPoint);
   SolidBrush   solidBrush(Color(255, 0, 0, 255));

   StringFormat stringFormat;
   stringFormat.SetTabStops(0, 3, tabs);
   graphics.DrawString(
      L"Name\tTest 1\tTest 2\tTest 3",
      25,
      &font,
      RectF(20, 20, 500, 100),
      &stringFormat,
      &solidBrush);

   // Draw the rectangle that encloses the text.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawRectangle(&pen, 20, 20, 500, 100);
}
```

## See also

[Formatting Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-formatting-text-use)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormat::GetTabStops](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-gettabstops)