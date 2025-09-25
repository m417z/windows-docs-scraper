# WICPngItxtProperties enumeration

## Description

Specifies the Portable Network Graphics (PNG) iTXT chunk metadata properties.

## Constants

### `WICPngItxtKeyword:0x1`

[VT_LPSTR] Indicates the keywords in the iTXT metadata chunk.

### `WICPngItxtCompressionFlag:0x2`

[VT_UI1] Indicates whether the text in the iTXT chunk is compressed. 1 if the text is compressed; otherwise, 0.

### `WICPngItxtLanguageTag:0x3`

[VT_LPSTR] Indicates the human language used by the translated keyword and the text.

### `WICPngItxtTranslatedKeyword:0x4`

[VT_LPWSTR] Indicates a translation of the keyword into the language indicated by the language tag.

### `WICPngItxtText:0x5`

[VT_LPWSTR] Indicates additional text in the iTXT metadata chunk.

### `WICPngItxtProperties_FORCE_DWORD:0x7fffffff`