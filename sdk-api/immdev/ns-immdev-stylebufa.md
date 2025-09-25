# STYLEBUFA structure

## Description

Contains the identifier and name of a style.

## Members

### `dwStyle`

Style of the register string. Can be IME_REGWORD_STYLE_EUDC to indicate a string in the EUDC range.

### `szDescription`

Description of the style.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)

## Remarks

> [!NOTE]
> The immdev.h header defines STYLEBUF as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).