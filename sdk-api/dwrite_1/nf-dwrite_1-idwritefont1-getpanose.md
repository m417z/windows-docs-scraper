# IDWriteFont1::GetPanose

## Description

Gets the PANOSE values from the font and is used for font selection and
matching.

## Parameters

### `panose` [out]

Type: **[DWRITE_PANOSE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_panose)***

A pointer to the [DWRITE_PANOSE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_panose) structure to fill in.

## Remarks

If the font has no PANOSE values,
they are set to 'any' (0) and [DirectWrite](https://learn.microsoft.com/windows/win32/DirectWrite/direct-write-portal) doesn't simulate those values.

## See also

[IDWriteFont1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefont1)