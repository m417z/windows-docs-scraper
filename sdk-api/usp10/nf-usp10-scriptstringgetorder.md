# ScriptStringGetOrder function

## Description

Creates an array that maps an original character position to a glyph position.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for the string.

### `puOrder` [out]

Pointer to a buffer in which this function retrieves an array of glyph positions, indexed by the original character position. The array should have room for at least the number of integers indicated by the *ssa* parameter of [ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars).

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

When the number of glyphs and the number of characters are equal, the function retrieves an array that references every glyph. This is the same treatment that occurs in [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa).

To use this function, the application needs to specify SSA_GLYPHS in its original call to [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse).

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)