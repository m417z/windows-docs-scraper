# ScriptIsComplex function

## Description

Determines whether a Unicode string requires complex script processing.

## Parameters

### `pwcInChars` [in]

Pointer to the string to test.

### `cInChars` [in]

Length of the input string, in characters.

### `dwFlags` [in]

Flags specifying testing details. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **SIC_ASCIIDIGIT** | Treat digits U+0030 to U+0039 as complex. The application sets this flag if the string is displayed with digit substitution enabled. If the application is following the user's National Language Support (NLS) settings using the [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution) function, it can pass a [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute) structure with the **DigitSubstitute** member set to SCRIPT_DIGITSUBSTITUTE_NONE. |
| **SIC_COMPLEX** | Treat complex script letters as complex. This flag should normally be set. |
| **SIC_NEUTRAL** | Treat neutrals as complex. The application sets this flag to display the string with right-to-left reading order. |

## Return value

Returns S_OK if the string requires complex script processing. The function returns S_FALSE if the string can be handled by standard API function calls, that is, it contains only characters laid out side-by-side and left-to-right. The function returns a nonzero HRESULT value if it does not succeed.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute)

[ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)