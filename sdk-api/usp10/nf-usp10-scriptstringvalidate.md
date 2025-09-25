# ScriptStringValidate function

## Description

Checks a [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for invalid sequences.

## Parameters

### `ssa` [in]

A [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure for a string.

## Return value

Returns S_OK if no invalid sequences are found. The function returns S_FALSE if one or more invalid sequences are found. The function returns a nonzero HRESULT value if it does not succeed.

## Remarks

This function is intended for use in editors that reject the input of invalid sequences.

Invalid sequences are only checked for scripts with the **fRejectInvalid** member set in the associated [SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties) structure. For example, it is conventional for Notepad to reject invalid Thai character sequences. However, invalid Indian sequences are not conventionally rejected, but instead are displayed in composition with a missing base character symbol.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties)

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)