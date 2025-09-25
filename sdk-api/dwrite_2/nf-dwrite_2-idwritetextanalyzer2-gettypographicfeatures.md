# IDWriteTextAnalyzer2::GetTypographicFeatures

## Description

Returns a complete list of OpenType features available for a script or font. If a feature is partially supported, then this method indicates that it is supported.

## Parameters

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

The font face to get features from.

### `scriptAnalysis`

Type: **[DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)**

The script analysis for the script or font to check.

### `localeName` [in, optional]

Type: **const WCHAR***

The locale name to check.

### `maxTagCount`

Type: **UINT32**

The maximum number of tags to return.

### `actualTagCount` [out]

Type: **UINT32***

The actual number of tags returned.

### `tags` [out]

Type: **[DWRITE_FONT_FEATURE_TAG](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_feature_tag)***

An array of OpenType font feature tags.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextanalyzer2)