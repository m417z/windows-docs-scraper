# IDebugClient4::OpenDumpFileWide

## Description

The **OpenDumpFileWide** method opens a dump file as a debugger target.

## Parameters

### `FileName` [in, optional]

Specifies the name of the dump file to open -- unless *FileHandle* is not zero, in which case *FileName* is used only when the engine is queried for the name of the dump file. *FileName* must include the file name extension. *FileName* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. *FileName* can also be in the form of a file URL, starting with "file://". If *FileName* specifies a cabinet (.cab) file, the cabinet file is searched for the first file with extension .kdmp, then .hdmp, then .mdmp, and finally .dmp.

### `FileHandle` [in]

Specifies the file handle of the dump file to open. If *FileHandle* is zero, *FileName* is used to open the dump file. Otherwise, if *FileName* is not **NULL**, the engine returns it when queried for the name of the dump file. If *FileHandle* is not zero and *FileName* is **NULL**, the engine will return **HandleOnly** for the file name.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The ASCII version of this method is [OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile).

**Note** The engine doesn't completely attach to the dump file until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. When a dump file is created from a process or kernel, information about the last event is stored in the dump file. After the dump file is opened, the next time execution is attempted, the engine will generate this event for the event callbacks. Only then does the dump file become available in the debugging session.

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[.opendump (Open Dump File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-opendump--open-dump-file-)

[AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile)

[AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OpenDumpFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfile)