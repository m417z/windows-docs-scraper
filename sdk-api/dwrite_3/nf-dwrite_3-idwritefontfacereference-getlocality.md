# IDWriteFontFaceReference::GetLocality

## Description

Get the locality of this font face reference.

## Return value

Type: **[DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)**

Returns the locality of this font face reference.

## Remarks

You can always successfully
create a font face from a fully local font. Attempting to create a font
face on a remote or partially local font may fail with DWRITE_E_REMOTEFONT.
This function may change between calls depending on background downloads
and whether cached data expires.

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)