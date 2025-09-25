# FontFamily::GetLastStatus

## Description

The **FontFamily::GetLastStatus** method returns a value that indicates the nature of this [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **FontFamily::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object have failed since the previous call to **FontFamily::GetLastStatus**, then **FontFamily::GetLastStatus** returns Ok.

If at least one method invoked on this [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object has failed since the previous call to **FontFamily::GetLastStatus**, then **FontFamily::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **FontFamily::GetLastStatus** immediately after constructing a [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object to determine whether the constructor succeeded.

The first time you call the **FontFamily::GetLastStatus** method of a
[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object, it returns Ok if the constructor succeeded and all methods invoked so far on the **FontFamily** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object and then checks the status of the call to create the object. If the call was successful, the example draws text.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a FontFamily object.
   FontFamily myFontFamily(L"arial");

   // Check the status of the last call.
   Status status = myFontFamily.GetLastStatus();

   // If the last call succeeded, draw text.
   if (status ==Ok)
   {
       SolidBrush solidbrush(Color(255, 0, 0, 0));
       Font       font(&myFontFamily, 16);
       WCHAR      string[] = L"status = Ok";
       graphics.DrawString(string, -1, &font, PointF(0, 0), &solidbrush);
   }
}
```

## See also

[Constructing Font Families and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-font-families-and-fonts-use)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)