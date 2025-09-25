# FontFamily::GetFamilyName

## Description

The **FontFamily::GetFamilyName** method gets the name of this font family.

## Parameters

### `name` [out]

Type: **WCHAR[LF_FACESIZE]**

Name of this font family.

### `language` [in]

Type: **WCHAR**

Optional. Sixteen-bit value that specifies the language to use. The default value is LANG_NEUTRAL, which is the user's default language.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

When specifying LANG_NEUTRAL as the language ID, it is common practice to pass just LANG_NEUTRAL as in the following example:

`stat = FontFamily.GetFamilyName(name, LANG_NEUTRAL);`

If you are specifying a language other than LANG_NEUTRAL, use MAKELANGID to create the language and sublanguage combination as in the following example:

`LANGID language = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_TRADITIONAL);`

For a listing of the available languages and sublanguages, see Winnt.h.

#### Examples

The following example creates a
**FontFamily** object, gets the family name, and outputs the name as text.

```cpp
VOID Example_GetFamilyName(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a FontFamily object.
   FontFamily nameFontFamily(L"arial");

   // Get the cell ascent of the font family in design units.
   WCHAR      familyName[LF_FACESIZE];
   nameFontFamily.GetFamilyName(familyName);

   // Copy the cell ascent into a string and draw the string.
   SolidBrush solidbrush(Color(255, 0, 0, 0));
   Font       font(&nameFontFamily, 16);
   graphics.DrawString(familyName, -1, &font, PointF(0, 0), &solidbrush);
}
```

## See also

[Constructing Font Families and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-font-families-and-fonts-use)

[Enumerating Installed Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-enumerating-installed-fonts-use)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)