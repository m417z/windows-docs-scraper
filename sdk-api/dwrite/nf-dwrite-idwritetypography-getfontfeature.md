# IDWriteTypography::GetFontFeature

## Description

 Gets the font feature at the specified index.

## Parameters

### `fontFeatureIndex`

Type: **UINT32**

The zero-based index of the font feature to retrieve.

### `fontFeature` [out]

Type: **[DWRITE_FONT_FEATURE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_feature)***

When this method returns, contains the font feature which is at the specified index.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A single run of text can be associated with more than one typographic feature. The [IDWriteTypography](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetypography) object holds a list of these font features.

## See also

[IDWriteTypography](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetypography)