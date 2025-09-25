# IDWriteFontFace1::HasKerningPairs

## Description

Determines whether the font supports pair-kerning.

## Return value

Returns TRUE if the font supports kerning pairs, otherwise FALSE.

## Remarks

If the font doesn't support pair table kerning, you don't need to
call [IDWriteFontFace1::GetKerningPairAdjustments](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getkerningpairadjustments) because it would retrieve all zeroes.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)

[IDWriteFontFace1::GetKerningPairAdjustments](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getkerningpairadjustments)