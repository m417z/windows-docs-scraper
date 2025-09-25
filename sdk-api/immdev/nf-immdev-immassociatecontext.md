# ImmAssociateContext function

## Description

Associates the specified input context with the specified window. By default, the operating system associates the default input context with each window as it is created.

**Note** To specify a type of association, the application should use the [ImmAssociateContextEx](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immassociatecontextex) function.

## Parameters

### `HWND` [in]

Handle to the window to associate with the input context.

### `HIMC` [in]

Handle to the input context. If *hIMC* is **NULL**, the function removes any association the window has with an input context. Thus IME cannot be used in the window.

## Return value

Returns the handle to the input context previously associated with the window.

## Remarks

When associating an input context with a window, an application must remove the association before destroying the input context. One way to do this is to save the handle and reassociate it to the default input context with the window.

## See also

[ImmAssociateContextEx](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immassociatecontextex)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)