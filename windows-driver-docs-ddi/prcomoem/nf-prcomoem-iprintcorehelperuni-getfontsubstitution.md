## Description

**IPrintCoreHelperUni::GetFontSubstitution** method indicates which device font, if any, is used as a substitution font for a specified TrueType font.

## Parameters

### `pszTrueTypeFontName` [in]

A pointer to a null-terminated Unicode string that contains the name of a TrueType font.

### `ppszDevFontName` [out]

A pointer to a variable that receives the address of a null-terminated Unicode string. This string contains the name of the device font that will be used in place of the TrueType font specified in the *pszFontName* parameter. If there is no device font that can serve as a substitute for the specified TrueType font, this parameter will be set to **NULL**.

## Return value

**IPrintCoreHelperUni::GetFontSubstitution** should return one of the following values:

| Return code | Description |
|---|---|
| **S_OK** | The method read the option for the specified feature. |
| **E_FAIL** | The font that was requested does not exist or was not a TrueType font. |
| **E_INVALIDARG** | One or more of the arguments is invalid. |
| **E_OUTOFMEMORY** | The core driver was not able to service the request because there was insufficient memory. |
| **E_UNEXPECTED, or other return codes not listed here** | The core driver seems to be in an invalid state. The caller should return a failure code. |

## Remarks

If an application attempts to print text that uses the TrueType font specified in the *pszTrueTypeFontName* parameter, that text will instead be printed in the device font specified in the *ppszDevFontName* parameter. The device font name must be that of a valid, installed font.

A font is identified by its font face name, which appears in the **lfFaceName** member of the [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure.

To obtain a list of available fonts, create an information context for the current printer, and call [**SetGraphicsMode**(hIC, GM_ADVANCED)](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-setgraphicsmode). Then enumerate device fonts by means of a call to [**EnumFontFamilies**](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesa). The callback parameter (see [**EnumFontFamProc**](https://learn.microsoft.com/previous-versions/dd162621(v=vs.85))) of [**EnumFontFamilies**](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesa) should filter for device fonts by incrementing a counter for each font for which the bitwise AND result (FontType & TRUETYPE_FONTTYPE) is nonzero.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::SetFontSubstitution](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-setfontsubstitution)