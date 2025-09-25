# FontCollection::GetFamilies

## Description

The **FontCollection::GetFamilies** method gets the font families contained in this font collection.

## Parameters

### `numSought` [in]

Type: **INT**

Integer that specifies the number of font families in this font collection.

### `gpfamilies` [out]

Type: **[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)***

Pointer to an array that receives the [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) objects.

### `numFound` [out]

Type: **INT***

Pointer to an **INT** that receives the number of font families found in this collection. This number should be the same as the *numSought* value.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration. If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

A font family consists of a single font type with related styles. An example of a single font type is Arial Regular. An example of a font family is a set of fonts containing Arial Regular, Arial Italic, and Arial Bold style fonts.

#### Examples

The following example creates a [PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection) object, gets the [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) objects contained within the collection, and uses one of the font families to draw text.

```cpp
VOID Example_GetFamilies(HDC hdc)
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

   // Create a Font object from the first FontFamily object in the array.
   Font myFont(&families[0], 16);

   // Use myFont to draw text.
   SolidBrush solidbrush(Color(255, 0, 0, 0));
   WCHAR string[] = L"This is an Arial font";
   graphics.DrawString(string,
                       21, &myFont, PointF(0, 0), &solidbrush);
}
```

## See also

[FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection)

[FontCollection::GetFamilyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontcollection-getfamilycount)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)