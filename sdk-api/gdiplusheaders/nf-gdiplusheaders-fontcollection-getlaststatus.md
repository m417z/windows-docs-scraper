# FontCollection::GetLastStatus

## Description

The **FontCollection::GetLastStatus** method returns a value that indicates the result of this [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object's previous method call.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **FontCollection::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the previous method invoked on this [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object succeeded, **FontCollection::GetLastStatus** returns Ok.

If the previous method failed, then **FontCollection::GetLastStatus** returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration that indicates the nature of the failure.

## Remarks

You can call **FontCollection::GetLastStatus** immediately after constructing a [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object to determine whether the constructor succeeded. **FontCollection::GetLastStatus** returns Ok if the constructor succeeded. Otherwise, it returns a value that indicates the nature of the failure.

Note that the implementation of **FontCollection::GetLastStatus** in the [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) and [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) classes is different from the implementation of this method in other classes. Also, the implementation of **FontCollection::GetLastStatus** in the **Font** class is different from the implementation of **FontCollection::GetLastStatus** in the **FontCollection** class.

#### Examples

The following example creates a [PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection) object, checks the status of a method call, and, if successful, draws text.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a PrivateFontCollection object, and add three families.
   PrivateFontCollection fontCollection;
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Arial.ttf");
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\CourBI.ttf");
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\TimesBd.ttf");

   // Create an array to hold the font families, and get the font families of
   // fontCollection.
   FontFamily families[3];
   int numFamilies;
   fontCollection.GetFamilies(3, families, &numFamilies);

   // Verify that the call to GetFamilies was successful.
   Status status = fontCollection.GetLastStatus();

   // If the call was successful, draw text.
   if (status == Ok)
   {
      // Create a Font object from the first FontFamily object in the array.
      Font myFont(&families[0], 16);

      // Use myFont to draw text.
      SolidBrush solidbrush(Color(255, 0, 0, 0));
      WCHAR string[] = L"The call was successful";
      graphics.DrawString(string,
                          23, &myFont, PointF(0, 0), &solidbrush);
   }
}
```

## See also

[FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)