# FontCollection::GetFamilyCount

## Description

The **FontCollection::GetFamilyCount** method gets the number of font families contained in this font collection.

## Return value

Type: **INT**

This method returns the number of font families contained in this font collection.

## Remarks

A font family consists of a single font type with related styles. An example of a single font type is Arial Regular. An example of a font family is a set of fonts containing Arial Regular, Arial Italic, and Arial Bold style fonts.

#### Examples

The following example creates a [PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection) object, gets the number of
[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) objects contained within the collection, and outputs that number.

```cpp
VOID Example_GetFamilyCount(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a PrivateFontCollection object, and add three families.
   PrivateFontCollection fontCollection;
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Arial.ttf");
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\CourBI.ttf");
   fontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\TimesBd.ttf");

   // Get the number of font families in the collection.
   int numFamilies = fontCollection.GetFamilyCount();

   // Print the number of families as text.
   SolidBrush solidbrush(Color(255, 0, 0, 0));
   Font       font(L"Arial", 16);
   WCHAR      string[256];
   swprintf_s(string, L"There are %i families in fontCollection.", numFamilies);
   graphics.DrawString(string,
                       wcslen(string), &font, PointF(0, 0), &solidbrush);
}
```

## See also

[FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)