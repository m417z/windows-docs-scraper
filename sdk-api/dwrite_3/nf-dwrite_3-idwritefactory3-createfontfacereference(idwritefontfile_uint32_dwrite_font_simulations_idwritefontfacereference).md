# IDWriteFactory3::CreateFontFaceReference(IDWriteFontFile,UINT32,DWRITE_FONT_SIMULATIONS,IDWriteFontFaceReference)

## Description

Creates a reference to a font given an **IDWriteFontFile**.

## Parameters

### `fontFile`

An **IDWriteFontFile** representing the font face.

### `faceIndex`

Type: **UINT32**

The zero based index of a font face in cases when the font files contain a collection of font faces.
If the font files contain a single face, this value should be zero.

### `fontSimulations`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Font face simulation flags for algorithmic emboldening and italicization.

### `fontFaceReference` [out]

Type: **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)****

Contains newly created font face reference object, or nullptr in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)