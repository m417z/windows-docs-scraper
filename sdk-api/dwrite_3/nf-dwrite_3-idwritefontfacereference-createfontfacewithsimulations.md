# IDWriteFontFaceReference::CreateFontFaceWithSimulations

## Description

Creates a font face with alternate font simulations, for example, to explicitly simulate a bold font face out of a regular variant.

## Parameters

### `fontFaceSimulationFlags`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Font face simulation flags for algorithmic emboldening and italicization.

### `fontFace` [out]

Type: **[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)****

Newly created font face object, or nullptr in the case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function can fail with DWRITE_E_REMOTEFONT if the font is not local.

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)