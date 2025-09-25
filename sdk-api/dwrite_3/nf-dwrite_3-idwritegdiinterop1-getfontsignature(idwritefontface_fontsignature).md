## Description

Reads the font signature from the given font.

## Parameters

### `fontFace`

Type: [in] **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)***

Font to read font signature from.

### `fontSignature`

Type: [out] **FONTSIGNATURE***

Font signature from the OS/2 table, ulUnicodeRange, and ulCodePageRange.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGdiInterop1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritegdiinterop1)