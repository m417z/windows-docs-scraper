# ScriptString_pSize function

## Description

Returns a pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure for an analyzed string.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for a string.

## Return value

Returns a pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure containing the size (width and height) of the analyzed string if successful. The function returns **NULL** if it does not succeed.

## Remarks

The size returned by this function is the size before the effect of the justification requested by setting the SSA_FIT flag in [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse). The difference between the value of *iReqWidth* in **ScriptStringAnalyse** and the size returned by **ScriptString_pSize** is the effect of justification.

The pointer returned by this function is valid only until the application passes the associated [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure to [ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree).

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)