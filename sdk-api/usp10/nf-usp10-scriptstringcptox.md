# ScriptStringCPtoX function

## Description

Retrieves the x coordinate for the leading or trailing edge of a character position.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for the string.

### `icp` [in]

Character position in the string.

### `fTrailing` [in]

**TRUE** to indicate the trailing edge of the character position (*icp*) that corresponds to the x coordinate. This parameter is set to **FALSE** to indicate the leading edge of the character position.

### `pX` [out]

Pointer to a buffer in which this function retrieves the x coordinate corresponding to the character position.

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)