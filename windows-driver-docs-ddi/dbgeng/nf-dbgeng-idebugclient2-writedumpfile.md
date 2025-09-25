# IDebugClient2::WriteDumpFile

## Description

The **WriteDumpFile** method creates a user-mode or kernel-modecrash dump file.

## Parameters

### `DumpFile` [in]

Specifies the name of the dump file to create. *DumpFile* must include the file name extension. *DumpFile* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started.

### `Qualifier` [in]

Specifies the type of dump file to create. For possible values, see Remarks.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The DEBUG_DUMP_*XXX* constants are used by the methods **WriteDumpFile**, [WriteDumpFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfile2), and [WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide) to specify the type of crash dump file to create.

The possible values include the following.

| Constant | Description |
| --- | --- |
| **DEBUG_DUMP_SMALL** | Creates a Small Memory Dump (kernel-mode) or Minidump (user-mode). |
| **DEBUG_DUMP_DEFAULT** | Creates a Full User-Mode Dump (user-mode) or Kernel Summary Dump (kernel-mode). |
| **DEBUG_DUMP_FULL** | Creates a Complete Memory Dump (kernel-mode only). |

To specify the formatting of the file and--for user-mode minidumps--the information to include in the file, use [WriteDumpFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfile2) or [WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide).

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

Moreover, the following aliases are available for kernel-mode debugging.

| Alias | Value |
| --- | --- |
| DEBUG_KERNEL_SMALL_DUMP | DEBUG_DUMP_SMALL |
| DEBUG_KERNEL_DUMP | DEBUG_DUMP_DEFAULT |
| DEBUG_KERNEL_FULL_DUMP | DEBUG_DUMP_FULL |

Additionally, the following aliases are available for user-mode debugging.

| Alias | Value |
| --- | --- |
| DEBUG_USER_WINDOWS_SMALL_DUMP | DEBUG_DUMP_SMALL |
| DEBUG_USER_WINDOWS_DUMP | DEBUG_DUMP_DEFAULT |

For a description of kernel-mode dump files, see [Varieties of Kernel-Mode Dump Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/varieties-of-kernel-mode-dump-files). For a description of user-mode dump files, see [Varieties of User-Mode Dump Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/user-mode-dump-files).

## See also

[.dump (Create Dump File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-dump--create-dump-file-)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[WriteDumpFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfile2)

[WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide)