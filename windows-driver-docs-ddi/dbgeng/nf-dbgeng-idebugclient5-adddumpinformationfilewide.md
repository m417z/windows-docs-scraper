# IDebugClient5::AddDumpInformationFileWide

## Description

The **AddDumpInformationFileWide** method registers additional files containing supporting information that will be used when opening a [dump file](https://learn.microsoft.com/windows-hardware/drivers/debugger/d). The ASCII version of this method is [AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile).

## Parameters

### `FileName` [in, optional]

Specifies the name of the file containing the supporting information. If *FileHandle* is not zero, *FileName* is used only for informational purposes.

### `FileHandle` [in]

Specifies the handle of the file containing the supporting information. If *FileHandle* is zero, the file named in *FileName* is used.

### `Type` [in]

Specifies the type of the file in *FileName* or *FileHandle*. Currently, only files containing paging file information are supported, and *Type* must be set to DEBUG_DUMP_FILE_PAGE_FILE_DUMP.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If supporting information is to be used when opening a dump file, this method or [AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile) must be called before [OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile) is called. If a session has already started, this method cannot be used.

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile)

[GetDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getdumpfile)

[GetNumberDumpFiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberdumpfiles)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile)

[OpenDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfilewide)