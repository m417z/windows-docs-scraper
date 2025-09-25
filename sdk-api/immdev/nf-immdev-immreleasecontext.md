# ImmReleaseContext function

## Description

Releases the input context and unlocks the memory associated in the input context. An application must call this function for each call to the [ImmGetContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immgetcontext) function.

## Parameters

### `HWND` [in]

Handle to the window for which the input context was previously retrieved.

### `HIMC` [in]

Handle to the input context.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[ImmGetContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immgetcontext)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)