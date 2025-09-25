# Font::GetLastStatus

## Description

The **Font::GetLastStatus** method returns a value that indicates the nature of this
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **Font::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object have failed, then **Font::GetLastStatus** returns Ok.

If at least one method invoked on this
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object has failed, then **Font::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Font::GetLastStatus** immediately after constructing a
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object to determine whether the constructor succeeded.

The first time you call the **Font::GetLastStatus** method of a
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object, it returns Ok if the constructor succeeded and all methods invoked so far on the
**Font** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object, checks to see that the call to create the object was successful, and, if it was, uses the
**Font** object to draw text.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Font object.
   Font myFont(L"Arial", 16);

   // Check the status of the last call.
   Status status = myFont.GetLastStatus();

   // If the call to create myFont succeeded, use myFont to write text.
   if (status == Ok)
   {
       SolidBrush solidbrush(Color(255, 0, 0, 0));
       WCHAR      string[] = L"The call succeeded";
       graphics.DrawString(string, 18, &myFont, PointF(0, 0), &solidbrush);
   }
}
```

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Font::IsAvailable](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-isavailable)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)