# REGISTERWORDA structure

## Description

Contains reading information or a word to register.

## Members

### `lpReading`

Pointer to the reading information for the word to register. If the reading information is not needed, the member can be set to **NULL**.

### `lpWord`

Pointer to the word to register. If a word is not needed, the member can be set to **NULL**.

## Remarks

The application can pass this structure to the [ImmConfigureIME](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immconfigureimea) function to have the information or word appear as an initial value in the configuration dialog box for the IME.

> [!NOTE]
> The imm.h header defines REGISTERWORD as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ImmConfigureIME](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immconfigureimea)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)