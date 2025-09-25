# ICallIndirect::GetStackSize

## Description

Retrieves the number of bytes that should be popped from the stack in order to return from an invocation of the method.

## Parameters

### `iMethod` [in]

The method number.

### `cbArgs` [out]

The number of bytes to be popped from the stack to clear the stack of arguments to an invocation.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect)