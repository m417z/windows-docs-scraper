# ImmGetCompositionFontA function

## Description

Retrieves information about the logical font currently used to display characters in the composition window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lplf` [out]

Pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure in which this function retrieves the font information.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The imm.h header defines ImmGetCompositionFont as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).