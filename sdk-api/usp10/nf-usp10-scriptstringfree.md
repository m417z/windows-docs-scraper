# ScriptStringFree function

## Description

Frees a [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure.

## Parameters

### `pssa` [in, out]

Pointer to a [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure.

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

When your application is finished with a [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure, it should free the associated memory by calling this function. After this function is called, the pointers retrieved from [ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars), [ScriptString_pLogAttr](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_plogattr), and [ScriptString_pSize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_psize) that are associated with the *pssa* parameter are invalid.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[ScriptString_pLogAttr](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_plogattr)

[ScriptString_pSize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_psize)

[ScriptString_pcOutChars](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstring_pcoutchars)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)