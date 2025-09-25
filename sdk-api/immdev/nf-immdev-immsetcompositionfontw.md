# ImmSetCompositionFontW function

## Description

Sets the logical font to use to display characters in the composition window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lplf` [in]

Pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure containing the font information to set.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function causes a [IMN_SETCOMPOSITIONFONT](https://learn.microsoft.com/windows/desktop/Intl/imn-setcompositionfont) command to be sent to an application. Even if the application never uses the composition window, it must set the appropriate font to ensure that characters are displayed properly. This is especially true for vertical writing.

> [!NOTE]
> The immdev.h header defines ImmSetCompositionFont as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IMN_SETCOMPOSITIONFONT](https://learn.microsoft.com/windows/desktop/Intl/imn-setcompositionfont)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)