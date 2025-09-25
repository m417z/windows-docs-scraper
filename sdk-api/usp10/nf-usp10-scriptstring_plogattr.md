# ScriptString_pLogAttr function

## Description

Returns a pointer to a logical attributes buffer for an analyzed string.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for the string.

## Return value

Returns a pointer to a buffer containing [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) structures defining logical attributes if successful. The function returns **NULL** if it does not succeed.

## Remarks

The pointer returned by this function is valid only until the application passes the associated [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure to [ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree).

The logical attribute buffer contains at least the number of integers indicated by the *ssa* parameter of [ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars).

When scanning the [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) array for a word break point, the application should look backward for the values of the **fWordStop** and **fWhiteSpace** members. [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse) just calls [ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak) on each run, and **ScriptBreak** never sets **fWordBreak** on the first character of a run, because it has no information that the previous run ended in white space.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak)

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree)

[ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)