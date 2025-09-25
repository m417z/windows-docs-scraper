# IDebugControl2::GetDumpFormatFlags

## Description

The **GetDumpFormatFlags** method returns the flags that describe what information is available in a dump file target.

## Parameters

### `FormatFlags` [out]

Receives the flags that describe the information included in a dump file. Different dump files support different sets of format information. For example, see [DEBUG_FORMAT_XXX](https://learn.microsoft.com/previous-versions/ff541497(v=vs.85)) for a description of the flags used for user-mode Minidump files.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available when debugging crash dump files. If the crash dump file is in a default format or does not have variable formats, zero will be returned to *FormatFlags*.

## See also

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[WriteDumpFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfile2)

[WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide)