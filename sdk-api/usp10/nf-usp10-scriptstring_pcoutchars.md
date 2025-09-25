# ScriptString_pcOutChars function

## Description

Returns a pointer to the length of a string after clipping.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for the string.

## Return value

Returns a pointer to the length of the string after clipping if successful. The length is the number of Unicode code points. The function returns **NULL** if it does not succeed.

## Remarks

To use this function, the application needs to specify SSA_CLIP in its original call to [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse).

The pointer returned by this function is valid only until the application passes the associated [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure to [ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree).

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)