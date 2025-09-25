# IDebugClient::OpenDumpFile

## Description

The **OpenDumpFile** method opens a dump file as a debugger target.

## Parameters

### `DumpFile` [in]

Specifies the name of the dump file to open. *DumpFile* must include the file name extension. *DumpFile* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. *DumpFile* can have the form of a file URL, starting with "file://". If *DumpFile* specifies a cabinet (.cab) file, the cabinet file is searched for the first file with extension .kdmp, then .hdmp, then .mdmp, and finally .dmp.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The Unicode version of this method is [OpenDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfilewide).

**Note** The engine doesn't completely attach to the dump file until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. When a dump file is created from a process or kernel, information about the last event is stored in the dump file. After the dump file is opened, the next time execution is attempted, the engine will generate this event for the event callbacks. Only then does the dump file become available in the debugging session.

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[.opendump (Open Dump File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-opendump--open-dump-file-)

[AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile)

[AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OpenDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-opendumpfilewide)