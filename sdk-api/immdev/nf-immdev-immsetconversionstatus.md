## Description

Sets the current conversion status.

## Parameters

### `unnamedParam1` [in]

Handle to the input context.

### `unnamedParam2` [in]

Conversion mode values. For more information, see [IME Conversion Mode Values](https://learn.microsoft.com/windows/desktop/Intl/ime-conversion-mode-values).

### `unnamedParam3` [in]

Sentence mode values. For more information, see [IME Sentence Mode Values](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values).

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function sends the [IMN_SETCONVERSIONMODE](https://learn.microsoft.com/windows/desktop/Intl/imn-setconversionmode) and [IMN_SETSENTENCEMODE](https://learn.microsoft.com/windows/desktop/Intl/imn-setsentencemode) commands to the application.

**Note** **Beginning with Windows 8:** By default, the input switch is set per user instead of per thread.
The Microsoft IME (Japanese) respects the mode globally, and therefore **ImmSetConversionStatus** fails when getting focus.

## See also

[IMN_SETCONVERSIONMODE](https://learn.microsoft.com/windows/desktop/Intl/imn-setconversionmode)

[IMN_SETSENTENCEMODE](https://learn.microsoft.com/windows/desktop/Intl/imn-setsentencemode)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)