# ImmRegisterWordA function

## Description

Registers a string with the dictionary of the IME associated with the specified input locale.

## Parameters

### `HKL` [in]

Input locale identifier.

### `lpszReading` [in]

Pointer to a null-terminated reading string associated with the string to register.

### `DWORD` [in]

Style of the string to register. This parameter can have any of the following values.

| Value | Meaning |
| --- | --- |
| **IME_REGWORD_STYLE_EUDC** | The string is in the end-user-defined (EUDC) range. |
| **Any value in the range from IME_REGWORD_STYLE_USER_FIRST to IME_REGWORD_STYLE_USER_LAST** | The string has a private style maintained by the specified IME. See the Remarks section for more details. |

### `lpszRegister` [in]

Pointer to the null-terminated string to register.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

An IME independent software vendor (ISV) can define private styles for an IME in the IME_REGWORD_STYLE_USER_FIRST and IME_REGWORD_STYLE_USER_LAST values. For example:

```cpp
#define MSIME_NOUN (IME_REGWORD_STYLE_USER_FIRST)
#define MSIME_VERB (IME_REGWORD_STYLE_USER_FIRST + 1)

```

> [!NOTE]
> The immdev.h header defines ImmRegisterWord as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)