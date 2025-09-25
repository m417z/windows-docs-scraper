# IDebugBreakpoint::SetCommand

## Description

The **SetCommand** method sets the command that is executed when a breakpoint is triggered.

## Parameters

### `Command` [in]

The command string that is executed when the breakpoint is triggered.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The command string is a list of debugger commands that are separated by semicolons. These commands are executed every time that the breakpoint is triggered. The commands are executed before the engine informs any event callbacks that the breakpoint has been triggered.

If the command string includes an execution command such as **G (Go)**, this command should be the last command in the *Command* string. If a command causes the target to resume execution, the rest of the command string is ignored.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).