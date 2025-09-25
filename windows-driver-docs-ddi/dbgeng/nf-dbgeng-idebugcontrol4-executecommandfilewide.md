# IDebugControl4::ExecuteCommandFileWide

## Description

The **ExecuteCommandFileWide** method opens the specified file and executes the debugger commands that are contained within.

## Parameters

### `OutputControl` [in]

Specifies where to send the output of the command. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `CommandFile` [in]

Specifies the name of the file that contains the commands to execute. This file is opened for reading and its contents are interpreted as if they had been typed into the debugger console.

### `Flags` [in]

Specifies execution options for the command. The default options are to log the command but not to send it to the output. For details about the values that *Flags* can take, see [Execute](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-execute).

## Return value

This method might also return error values, including error values caused by a failure to open the specified file. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method reads the specified file and execute the commands one line at a time using [Execute](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-execute). If an exception occurred while executing a line, the execution will continue with the next line.

## See also

[Execute](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-execute)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)