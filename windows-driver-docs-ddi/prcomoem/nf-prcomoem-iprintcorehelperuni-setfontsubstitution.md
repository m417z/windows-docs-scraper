# IPrintCoreHelperUni::SetFontSubstitution

## Description

The `IPrintCoreHelperUni::SetFontSubstitution` method specifies the device font to print in place of a given TrueType font.

## Parameters

### `pszTrueTypeFontName` [in]

A pointer to a null-terminated Unicode string that contains a valid TrueType font name. This parameter must not be **NULL**.

### `pszDevFontName` [in]

A pointer to a null-terminated Unicode string that contains the name of the device font.

## Return value

`IPrintCoreHelperUni::SetFontSubstitution` should return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method read the option for the specified feature. |
| **E_FAIL** | The font that was requested does not exist or was not a TrueType font. |
| **E_INVALIDARG** | One or more of the arguments is invalid. |
| **E_OUTOFMEMORY** | The core driver was not able to service the request because there was insufficient memory. |
| **E_UNEXPECTED, or other return codes not listed here** | The core driver seems to be in an invalid state. The caller should return a failure code. |

## Remarks

Setting a device font to use in place of a specified TrueType font can occur only during the device property sheets session and only if full UI replacement is enabled. The font that is represented by the *pszTrueTypeFontName* parameter must be a valid TrueType font and must be installed on the printer. The device font that is represented by the *pszDevFontName* parameter must be a valid font for this printer.

If a substitution mapping for the specified TrueType font already exists on this queue, the `SetFontSubstitution` method will silently replace the mapping. To remove a substitution mapping, call this method with the TrueType font name specified in *pszTrueTypeFontName* and with **NULL** specified in *pszDevFontName*.

To obtain a list of valid device fonts, create an information context for the current printer, and call **SetGraphicsMode**(hIC, GM_ADVANCED). Then, enumerate device fonts by calling **EnumFontFamilies**. The callback parameter (see **EnumFontFamProc** in the Microsoft Windows SDK documentation) of **EnumFontFamilies** should filter for device fonts by incrementing a counter for each font for which the bitwise AND result (FontType & TRUETYPE_FONTTYPE) is nonzero. The **SetGraphicsMode**, **EnumFontFamilies**, and **EnumFontFamProc** functions are described in the Windows SDK documentation.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::GetFontSubstitution](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-getfontsubstitution)