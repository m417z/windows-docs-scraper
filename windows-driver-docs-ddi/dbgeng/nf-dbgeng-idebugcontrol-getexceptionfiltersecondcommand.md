# IDebugControl::GetExceptionFilterSecondCommand

## Description

The **GetExceptionFilterSecondCommand** method returns the command that will be executed by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) upon the second chance of a specified [exception](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `Index` [in]

Specifies the index of the exception filter whose second-chance command will be returned. *Index* can also refer to the default exception filter to return the second-chance command for those exceptions that do not have a specific or arbitrary exception filter.

### `Buffer` [out, optional]

Receives the second-chance command for the exception filter.

### `BufferSize` [in]

Specifies the size, in characters, of the buffer that *Buffer* specifies. This size includes the space for the '\0' terminating character.

### `CommandSize` [out, optional]

Receives the size, in characters, of the second-chance command for the exception filter. This size includes the space for the '\0' terminating character. If *CommandSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Only exception filters support a second-chance command. If *Index* refers to a [specific event filter](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx), the command returned to *Buffer* will be empty. The returned command will also be empty if no second-chance command has been set for the specified exception.

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetEventFilterCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-geteventfiltercommand)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExceptionFilterSecondCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexceptionfiltersecondcommand)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)