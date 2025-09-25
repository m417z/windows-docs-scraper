# IDebugControl::GetLogFile

## Description

The **GetLogFile** method returns the name of the currently open log file.

## Parameters

### `Buffer` [out, optional]

Receives the name of the currently open log file. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `FileSize` [out, optional]

Receives the size, in characters, of the name of the log file. If *FileSize* is **NULL**, this information is not returned.

### `Append` [out]

Receives **TRUE** if log messages are appended to the log file, or **FALSE** if the contents of the log file were discarded when the file was opened.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the name of the log file was too long to fit in the *Buffer* buffer so the name was truncated. |
| **E_NOINTERFACE** | There is no currently open log file. |

## Remarks

**GetLogFile** and **GetLogFileWide** behave the same way as [GetLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getlogfile2) and **GetLogFile2Wide** with *Append* receiving only the information about the DEBUG_LOG_APPEND flag.

For more information about log files, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[CloseLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-closelogfile)

[GetLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getlogfile2)

[GetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogmask)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OpenLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-openlogfile)