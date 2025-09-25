# ScriptStringXtoCP function

## Description

Converts an x coordinate to a character position.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for the string.

### `iX` [in]

The x coordinate.

### `piCh` [out]

Pointer to a variable in which this function retrieves the character position corresponding to the x coordinate.

### `piTrailing` [out]

Pointer to a variable in which this function retrieves a value indicating if the x coordinate is for the leading edge or the trailing edge of the character position. For more information, see the Remarks section.

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

If the x coordinate corresponds to the leading edge of the character, the value of *piTrailing* is 0. If the x coordinate corresponds to the trailing edge of the character, the value of *piTrailing* is a positive integer. As for [ScriptXtoCP](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptxtocp), the value is 1 for a character that can be rendered on its own. The value is greater than 1 if the character is part of a cluster in a script for which cursors are not placed within a cluster, to indicate the offset to the next legitimate logical cursor position.

If the x coordinate is before the beginning of the line, the function retrieves -1 for *piCh* and 1 for *piTrailing*, indicating the trailing edge of the nonexistent character before the line. If the x coordinate is after the end of the line, the function retrieves for *piCh* the first index beyond the length of the line and 0 for *piTrailing*. The 0 value indicates the leading edge of the nonexistent character after the line.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)