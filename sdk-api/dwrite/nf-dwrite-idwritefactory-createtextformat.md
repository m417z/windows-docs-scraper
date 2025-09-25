# IDWriteFactory::CreateTextFormat

## Description

 Creates a text format object used for text layout.

## Parameters

### `fontFamilyName` [in]

Type: **const WCHAR***

An array of characters that contains the name of the font family

### `fontCollection`

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)***

A pointer to a font collection object. When this is **NULL**, indicates the system font collection.

### `fontWeight`

Type: **[DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight)**

A value that indicates the font weight for the text object created by this method.

### `fontStyle`

Type: **[DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style)**

A value that indicates the font style for the text object created by this method.

### `fontStretch`

Type: **[DWRITE_FONT_STRETCH](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_stretch)**

A value that indicates the font stretch for the text object created by this method.

### `fontSize`

Type: **FLOAT**

The logical size of the font in DIP ("device-independent pixel") units. A DIP equals 1/96 inch.

### `localeName` [in]

Type: **const WCHAR***

An array of characters that contains the locale name.

### `textFormat` [out]

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)****

When this method returns, contains an address of a pointer to a newly created text format object, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)