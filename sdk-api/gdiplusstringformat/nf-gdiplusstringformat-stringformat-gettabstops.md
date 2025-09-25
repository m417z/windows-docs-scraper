# StringFormat::GetTabStops

## Description

The **StringFormat::GetTabStops** method gets the offsets of the tab stops in this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object.

## Parameters

### `count` [in]

Type: **INT**

Integer that specifies the number of tab-stop offsets in the
*tabStops* array.

### `firstTabOffset` [out]

Type: **REAL***

Pointer to a
**REAL** that receives the initial offset position. This initial offset position is relative to the string's origin and the offset of the first tab stop is relative to the initial offset position.

### `tabStops` [out]

Type: **REAL***

Pointer to an array of type
**REAL** that receives the tab-stop offsets. The offset of the first tab stop is the first value in the array, the offset of the second tab stop, the second value in the array, and so on.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Each tab-stop offset in the
*tabStops* array, except the first one, is relative to the previous one. The first tab-stop offset is relative to the initial offset position indicated by
*firstTabOffset*. For example, if the initial offset position is 8 and the first tab-stop offset is 50, then the first tab stop is at position 58. If the initial offset position is zero, then the first tab-stop offset is relative to position 0, the string origin.

#### Examples

The following example creates a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object, sets tab stops, and uses the
**StringFormat** object to draw a string that contains tab characters (\t). The code also draws the string's layout rectangle. Then, the code gets the tab stops and proceeds to use or inspect the tab stops in some way.

```cpp
VOID Example_GetTabStop(HDC hdc)
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

   // Get the tab stops.
   INT   tabStopCount = 0;
   REAL  firstTabOffset = 0;
   REAL* tabStops = NULL;

   tabStopCount = stringFormat.GetTabStopCount();
   tabStops = (REAL*)malloc(tabStopCount*sizeof(REAL));
   stringFormat.GetTabStops(tabStopCount, &firstTabOffset, tabStops);

   for(INT j = 0; j < tabStopCount; ++j)
   {
      // Inspect or use the value in tabStops[j].
   }
}
```

## See also

[Formatting Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-formatting-text-use)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)