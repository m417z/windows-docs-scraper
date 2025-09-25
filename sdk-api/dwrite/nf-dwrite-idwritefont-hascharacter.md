# IDWriteFont::HasCharacter

## Description

 Determines whether the font supports a specified character.

## Parameters

### `unicodeValue`

Type: **UINT32**

A Unicode (UCS-4) character value for the method to inspect.

### `exists` [out]

Type: **BOOL***

When this method returns, **TRUE** if the font supports the specified character; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)

[IDWriteFontFace1::GetUnicodeRanges](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getunicoderanges)