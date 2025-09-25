# ScriptApplyDigitSubstitution function

## Description

Applies the specified digit substitution settings to the specified script control and script state structures.

## Parameters

### `psds` [in]

Pointer to a [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute) structure. The application sets this parameter to **NULL** if the function is to call [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution) with LOCALE_USER_DEFAULT.

### `psc` [out]

Pointer to a [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) structure with the **fContextDigits** and **uDefaultLanguage** members updated.

### `pss` [out]

Pointer to a [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) structure with the **fDigitSubstitute** member updated.

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed.

The function returns E_INVALIDARG if it does not recognize the **DigitSubstitute** member of [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute).

## Remarks

This function does not actually substitute digits. It just fills in the structures that describe the digit substitution policy. See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Digit Shapes](https://learn.microsoft.com/windows/desktop/Intl/digit-shapes)

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control)

[SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute)

[SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state)

[ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)