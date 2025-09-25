# IDebugControl3::Execute

## Description

The **Execute** method executes the specified debugger commands.

## Parameters

### `OutputControl` [in]

Specifies the output control to use while executing the command. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `Command` [in]

Specifies the command string to execute. The command is interpreted like those typed into a debugger command window. This command string can contain multiple commands for the engine to execute. See [Debugger Commands](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugger-commands) for the command reference.

### `Flags` [in]

Specifies a bit field of execution options for the command. The default options are to log the command but to not send it to the output. The following table lists the bits that can be set.

| Value | Description |
| --- | --- |
| DEBUG_EXECUTE_ECHO | The command string is sent to the output. |
| DEBUG_EXECUTE_NOT_LOGGED | The command string is not logged. This is overridden by DEBUG_EXECUTE_ECHO. |
| DEBUG_EXECUTE_NO_REPEAT | If *Command* is an empty string, do not repeat the last command, and do not save the current command string for repeat execution later. |

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method executes the given command string. If the string has multiple commands, this method will not return until all of the commands have been executed. If the sequence of commands involves waiting for the target to execute, this method can take an arbitrary amount of time to complete.

**Note** It is important to understand what it means for a step command to execute. A step command initiates a stepping action but does not wait for the stepping to complete. For example, suppose you call **IDebugControl::Execute** and pass a command string that contains the single command [pct](https://learn.microsoft.com/windows-hardware/drivers/debugger/pct--step-to-next-call-or-return-). The **pct** command initiates a step to the next call or return instruction, but **pct** completes its execution before the stepping takes place. Consequently, **IDebugControl::Execute** returns before the stepping takes place. Trace and go commands behave in a similar way. Examples of commands that have this behavior include [g](https://learn.microsoft.com/windows-hardware/drivers/debugger/g--go-), [gh](https://learn.microsoft.com/windows-hardware/drivers/debugger/gh--go-with-exception-handled-), [ta](https://learn.microsoft.com/windows-hardware/drivers/debugger/ta--trace-to-address-), [tb](https://learn.microsoft.com/windows-hardware/drivers/debugger/tb--trace-to-next-branch-), [tct](https://learn.microsoft.com/windows-hardware/drivers/debugger/tct--trace-to-next-call-or-return-), [pa](https://learn.microsoft.com/windows-hardware/drivers/debugger/pa--step-to-address-), and [pc](https://learn.microsoft.com/windows-hardware/drivers/debugger/pc--step-to-next-call-).

## See also

[ExecuteCommandFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-executecommandfile)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)