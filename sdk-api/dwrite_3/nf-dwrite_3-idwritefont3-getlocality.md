# IDWriteFont3::GetLocality

## Description

Gets the current locality of the font.

## Return value

Type: **[DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)**

Returns the current locality of the font.

## Remarks

For fully local files, the result will always be DWRITE_LOCALITY_LOCAL. A downloadable file may be any of the states, and this function may change between calls.

## See also

[IDWriteFont3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefont3)