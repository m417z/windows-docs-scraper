# IDebugBreakpoint2::GetCommand

## Description

The **GetCommand** method returns the command string that is executed when a breakpoint is triggered.

## Parameters

### `Buffer` [out, optional]

The command string that is executed when the breakpoint is triggered. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

The size, in characters, of the buffer that *Buffer* points to.

### `CommandSize` [out, optional]

The size of the command string. If *CommandSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful, but the buffer was not large enough to hold the command string and so the command string was truncated to fit. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The command string is a list of debugger commands that are separated by semicolons. These commands are executed every time that the breakpoint is triggered. The commands are executed before the engine informs any event callbacks that the breakpoint has been triggered.

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the size of the breakpoint's command, *CommandSize*.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).