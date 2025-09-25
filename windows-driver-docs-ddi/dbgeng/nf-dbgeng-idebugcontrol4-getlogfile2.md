# IDebugControl4::GetLogFile2

## Description

The **GetLogFile2** method returns the name of the currently open log file.

## Parameters

### `Buffer` [out, optional]

Receives the name of the currently open log file. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `FileSize` [out, optional]

Receives the size, in characters, of the name of the log file. If *FileSize* is **NULL**, this information is not returned.

### `Flags` [out]

Receives the bit-flags that were used when opening the log file. See the *Flags* parameter of [OpenLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-openlogfile2) for a description of these flags.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the name of the log file was too long to fit in the *Buffer* buffer so the name was truncated. |
| **E_NOINTERFACE** | There is no currently open log file. |

## Remarks

For more information about log files, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[CloseLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-closelogfile)

[GetLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogfile)

[GetLogMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlogmask)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OpenLogFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-openlogfile2)