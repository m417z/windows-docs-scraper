# IDebugControl::SetEventFilterCommand

## Description

The **SetEventFilterCommand** method sets a debugger command for the engine to execute when a specified event occurs.

## Parameters

### `Index` [in]

Specifies the index of the event filter. *Index* can take any value between zero and one less than the total number of event filters returned by **GetNumberEventFilters** (inclusive). For more information about the index of the filters, see Index and Exception Code.

### `Command` [in]

Specifies the debugger command for the engine to execute when the event occurs.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about event filters, see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetEventFilterCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-geteventfiltercommand)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExceptionFilterSecondCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexceptionfiltersecondcommand)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)