# ICallIndirect::CallIndirect

## Description

Invokes one of the methods in the interface with an indirect reference to the arguments of the invocation.

## Parameters

### `phrReturn` [out]

The value returned from the invocation of the method.

### `iMethod` [in]

The method number to be invoked.

### `pvArgs` [in]

A pointer to the stack frame with which to make the invocation. Details of the exact representation of this stack frame are processor-architecture specific.

### `cbArgs` [out]

The number of bytes to be popped from the stack to clear the stack of arguments to this invocation.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect)