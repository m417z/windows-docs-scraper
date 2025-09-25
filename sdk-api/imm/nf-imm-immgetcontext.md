# ImmGetContext function

## Description

Returns the input context associated with the specified window.

## Parameters

### `HWND` [in]

Handle to the window for which to retrieve the input context.

## Return value

Returns the handle to the input context.

## Remarks

An application should routinely use this function to retrieve the current input context before attempting to access information in the context.

The application must call [ImmReleaseContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immreleasecontext) when it is finished with the input context.

## See also

[ImmReleaseContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immreleasecontext)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)