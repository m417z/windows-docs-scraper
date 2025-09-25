# IDebugControl2::GetEventFilterCommand

## Description

The **GetEventFilterCommand** method returns the debugger command that the engine will execute when a specified event occurs.

## Parameters

### `Index` [in]

Specifies the index of the event filter. *Index* can take any value between zero and one less than the total number of event filters returned by [GetNumberEventFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbereventfilters) (inclusive). For more information about the index of the filters, see Index and Exception Code.

### `Buffer` [out, optional]

Receives the debugger command that the engine will execute when the event occurs.

### `BufferSize` [in]

Specifies the size, in characters, of the buffer that *Buffer* specifies. This size includes the space for the '\0' terminating character.

### `CommandSize` [out, optional]

Receives the size in characters of the command. This size includes the space for the '\0' terminating character. If *CommandSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about event filters, see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetExceptionFilterSecondCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexceptionfiltersecondcommand)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetEventFilterCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-seteventfiltercommand)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)