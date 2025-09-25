# IDWriteFontFace3::GetPanose

## Description

Gets the PANOSE values from the font, used for font selection and matching.

## Parameters

### `panose` [out]

Type: **[DWRITE_PANOSE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_panose)***

A pointer to a [DWRITE_PANOSE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_panose) structure that receives the PANOSE values from the font.

## Remarks

This method doesn't simulate these values, such as substituting a weight or proportion inferred on other values. If the font doesn't specify them, they are all set to 'any' (0).

## See also

[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)