# PrivateFontCollection::AddFontFile

## Description

The **PrivateFontCollection::AddFontFile** method adds a font file to this private font collection.

## Parameters

### `filename` [in]

Type: **const WCHAR***

Pointer to a wide-character string that specifies the name of a font file.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

When you use the GDI+ API, you must never allow your application to download arbitrary fonts from untrusted sources.
The operating system requires elevated privileges to assure that all installed fonts are trusted.

#### Examples

The following example creates a [PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection) object and adds three font files to the collection. The code then gets the font families that are in the collection and, for each family in the collection, creates a font which is used to draw text.

```cpp
VOID Example_AddFontFile(HDC hdc)
{
   Graphics              graphics(hdc);
   SolidBrush            solidBrush(Color(255, 0, 0, 0));
   INT                   found = 0;
   INT                   count = 0;
   WCHAR                 familyName[50];
   FontFamily*           pFontFamily;
   PrivateFontCollection privateFontCollection;

   // Add three font files to the private collection.
   privateFontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Arial.ttf");
   privateFontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Cour.ttf");
   privateFontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Times.ttf");

   // How many font families are in the private collection?
   count = privateFontCollection.GetFamilyCount();

   // Allocate a buffer to hold the array of FontFamily objects returned by
   // the GetFamilies method.
   pFontFamily = (FontFamily*)malloc(count * sizeof(FontFamily));

   // Get the array of FontFamily objects.
   privateFontCollection.GetFamilies(count, pFontFamily, &found);

   for(INT j = 0; j < found; ++j)
   {
      // Get the font family name.
      pFontFamily[j].GetFamilyName(familyName);

      // Pass the family name and the address of the private collection to a
      // Font constructor.
      Font* pFont = new Font(familyName, 16, FontStyleRegular,
                             UnitPixel, &privateFontCollection);

      // Use the font to draw a string.
      graphics.DrawString(
                          L"Hello",
                          5,          // string length
                          pFont,
                          PointF(10.0f, (REAL)j*25),
                          &solidBrush);

      delete(pFont);
   }

   free(pFontFamily);
}
```

## See also

[Creating a Private Font Collection](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-private-font-collection-use)

[InstalledFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-installedfontcollection)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)