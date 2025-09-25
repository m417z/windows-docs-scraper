# ImmDestroyContext function

## Description

Releases the input context and frees associated memory.

## Parameters

### `HIMC` [in]

Handle to the input context to free.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

Any application that creates an input context by using the [ImmCreateContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immcreatecontext) function must call this function to free the context before it terminates. However, before calling **ImmDestroyContext**, the application must remove the input context from any association with windows in the thread by using the [ImmAssociateContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immassociatecontext) function.

## See also

[ImmAssociateContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immassociatecontext)

[ImmCreateContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immcreatecontext)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)