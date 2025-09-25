# IDebugControl4::OpenLogFile2Wide

## Description

The **OpenLogFile2Wide** method opens a log file that will receive output from the [client objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects).

## Parameters

### `File` [in]

Specifies the name of the log file. *File* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. If the file does not exist, it will be created.

### `Flags` [in]

Specifies the bit-flags that control the nature of the log file. *Flags* can contain flags from the following table.

| Flag | Effect when set |
| --- | --- |
| DEBUG_LOG_APPEND | Output will be appended to the log file instead of discarding the contents of the log file. |
| DEBUG_LOG_UNICODE | The format of the log file will be Unicode instead of ASCII. |

Alternatively, *Flags* can be set to DEBUG_LOG_DEFAULT for the default set of options that contains none of the flags.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Only one log file can be open at a time. If there is already a log file open, it will be closed.

For more information about log files, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[.logappend (Append Log File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-logappend--append-log-file-)

[.logopen (Open Log File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-logopen--open-log-file-)

[CloseLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-closelogfile)

[GetLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getlogfile2)

[GetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogmask)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OpenLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-openlogfile)

[SetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setlogmask)