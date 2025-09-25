# IDWriteFontFace3::IsCharacterLocal

## Description

Determines whether the character is locally downloaded from the font.

## Parameters

### `unicodeValue` [in]

Type: **UINT32**

A Unicode (UCS-4) character value.

## Return value

Type: **BOOL**

Returns **TRUE** if the font has the specified character locally available,
**FALSE** if not or if the font does not support that character.

## See also

[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)