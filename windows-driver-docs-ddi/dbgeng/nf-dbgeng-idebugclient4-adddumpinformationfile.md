# IDebugClient4::AddDumpInformationFile

## Description

The **AddDumpInformationFile** method registers additional files containing supporting information that will be used when opening a dump file. The Unicode version of this method is [AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide).

## Parameters

### `InfoFile` [in]

Specifies the name of the file containing the supporting information.

### `Type` [in]

Specifies the type of the file *InfoFile*. Currently, only files containing paging file information are supported, and *Type* must be set to DEBUG_DUMP_FILE_PAGE_FILE_DUMP.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If supporting information is to be used when opening a dump file, this method or [AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide) must be called before [OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile) is called. If a session has already started, this method cannot be used.

For more information about crash dump files, see [Dump File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide)

[GetDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getdumpfile)

[GetNumberDumpFiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberdumpfiles)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile)

[OpenDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfilewide)