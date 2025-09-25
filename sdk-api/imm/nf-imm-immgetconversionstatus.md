# ImmGetConversionStatus function

## Description

Retrieves the current conversion status.

## Parameters

### `HIMC` [in]

Handle to the input context for which to retrieve status information.

### `lpfdwConversion` [out, optional]

Pointer to a variable in which the function retrieves a combination of conversion mode values. For more information, see [IME Conversion Mode Values](https://learn.microsoft.com/windows/desktop/Intl/ime-conversion-mode-values).

### `lpfdwSentence` [out, optional]

Pointer to a variable in which the function retrieves a sentence mode value. For more information, see [IME Sentence Mode Values](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values).

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

Conversion and sentence mode values are set only if the IME supports those modes.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)