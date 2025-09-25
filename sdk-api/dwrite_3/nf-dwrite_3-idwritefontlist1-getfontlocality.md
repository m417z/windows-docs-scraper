# IDWriteFontList1::GetFontLocality

## Description

Gets the current location of a font given its zero-based index.

## Parameters

### `listIndex` [in]

Type: **UINT32**

Zero-based index of the font in the font list.

## Return value

Type: **[DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)**

Returns a [DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)-typed value that specifies the location of the specified font.

## Remarks

For fully local files, the result will always be **DWRITE_LOCALITY_LOCAL**. For streamed files, the result depends on how much of the file has been downloaded. [GetFont](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontlist1-getfont) fails if the locality is **DWRITE_LOCALITY_REMOTE** and potentially fails if **DWRITE_LOCALITY_PARTIAL**.

## See also

[IDWriteFontList1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontlist1)