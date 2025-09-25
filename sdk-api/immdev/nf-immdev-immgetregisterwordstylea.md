# ImmGetRegisterWordStyleA function

## Description

Retrieves a list of the styles supported by the IME associated with the specified input locale.

## Parameters

### `HKL` [in]

Input locale identifier.

### `nItem` [in]

Maximum number of styles that the output buffer can hold. The application sets this parameter to 0 if the function is to count the number of styles available in the IME.

### `lpStyleBuf` [out]

Pointer to a [STYLEBUF](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-stylebufa) structure in which the function retrieves the style information.

## Return value

Returns the number of styles copied to the buffer. If the application sets the *nItem* parameter to 0, the return value is the number of styles available in the IME.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[STYLEBUF](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-stylebufa)

## Remarks

> [!NOTE]
> The immdev.h header defines ImmGetRegisterWordStyle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).