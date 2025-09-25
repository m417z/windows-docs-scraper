# TTGetNewFontName function

## Description

Obtains the family name for the font loaded through [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont).

## Parameters

### `phFontReference` [in]

Handle that identifies the embedded font that has been installed. The handle references an internal structure, not an Hfont.

### `wzWinFamilyName` [out]

Buffer to hold the new 16-bit-character Microsoft Windows family name.

### `cchMaxWinName` [in]

Length of the string allocated for the Windows name (*szWinFamilyName*). Must be at least LF_FACESIZE long.

### `szMacFamilyName` [out]

Buffer to hold the new 8-bit-character MacIntosh family name.

### `cchMaxMacName` [in]

Length of the string allocated for the Macintosh name (*szMacFamilyName*). Must be at least LF_FACESIZE long.

## Return value

If successful, returns E_NONE.

The font family name is a string in *szWinFamilyName* or *szMacFamilyName*.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

**Note** This function returns the font family name in the appropriate string buffer, either for Windows or the MacIntosh. The buffer for the other operating system is not used.

## See also

[TTGetEmbeddedFontInfo](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddedfontinfo)

[TTGetEmbeddingType](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddingtype)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)