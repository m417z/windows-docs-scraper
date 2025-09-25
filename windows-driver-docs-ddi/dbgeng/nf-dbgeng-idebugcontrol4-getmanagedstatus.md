# IDebugControl4::GetManagedStatus

## Description

 Provides feedback on the engine's
use of the runtime debugging APIs provided by the common language runtime (CLR).

## Parameters

### `Flags` [out, optional]

A pointer to flags from the debugging APIs.

### `WhichString` [in]

A value that controls which string to use.

### `String` [out]

A pointer to a string from the debugging APIs.

### `StringSize` [in]

The size of the string.

### `StringNeeded` [out, optional]

A pointer to an output string.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

Managed debugging support relies on debugging functionality provided by the CLR.

## See also

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)