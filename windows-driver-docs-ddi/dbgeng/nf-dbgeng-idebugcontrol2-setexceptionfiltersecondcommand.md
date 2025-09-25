# IDebugControl2::SetExceptionFilterSecondCommand

## Description

The **SetExceptionFilterSecondCommand** method sets the command that will be executed by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) on the second chance of a specified [exception](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `Index` [in]

Specifies the index of the exception filter whose second-chance command will be set. *Index* must not refer to the specific event filters as these are not exception filters and only exception events get a second chance. If *Index* refers to the default exception filter, the second-chance command is set for all exceptions that do not have an exception filter.

### `Command` [in]

Receives the second-chance command for the exception filter.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetExceptionFilterSecondCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexceptionfiltersecondcommand)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetEventFilterCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-seteventfiltercommand)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)