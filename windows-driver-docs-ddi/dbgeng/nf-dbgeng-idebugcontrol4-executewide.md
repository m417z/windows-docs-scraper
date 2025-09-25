# IDebugControl4::ExecuteWide

## Description

The **ExecuteWide** method executes the specified debugger commands.

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

This method executes the given command string. If the string has multiple commands, these methods will not return until all of the commands have been executed. This may involve waiting for the target to execute, so these methods can take an arbitrary amount of time to complete.

## See also

[ExecuteCommandFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-executecommandfile)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)