# ImmSetCompositionWindow function

## Description

Sets the position of the composition window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lpCompForm` [in]

Pointer to a [COMPOSITIONFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-compositionform) structure that contains the new position and other related information about the composition window.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function causes an [IMN_SETCOMPOSITIONWINDOW](https://learn.microsoft.com/windows/desktop/Intl/imn-setcompositionwindow) command to be sent to the application.

## See also

[COMPOSITIONFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-compositionform)

[IMN_SETCOMPOSITIONWINDOW](https://learn.microsoft.com/windows/desktop/Intl/imn-setcompositionwindow)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)