# IDebugControl3::OpenLogFile

## Description

The **OpenLogFile** method opens a log file that will receive output from the [client objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects).

## Parameters

### `File` [in]

Specifies the name of the log file. *File* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. If the file does not exist, it will be created.

### `Append` [in]

Specifies whether or not to append log messages to an existing log file. If **TRUE**, log messages will be appended to the file; if **FALSE**, the contents of any existing file matching *File* are discarded.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

**OpenLogFile** and **OpenLogFileWide** behave the same way as [OpenLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-openlogfile2) and **OpenLogFile2Wide** with *Flags* set to DEBUG_LOG_APPEND if *Append* is **TRUE** and DEBUG_LOG_DEFAULT otherwise.

Only one log file can be open at a time. If there is already a log file open, it will be closed.

For more information about log files, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[.logappend (Append Log File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-logappend--append-log-file-)

[.logopen (Open Log File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-logopen--open-log-file-)

[CloseLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-closelogfile)

[GetLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogfile)

[GetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogmask)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OpenLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-openlogfile2)

[SetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setlogmask)