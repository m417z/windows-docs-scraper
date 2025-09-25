# IDebugClient4::WriteDumpFile2

## Description

The **WriteDumpFile2** method creates a user-mode or kernel-modecrash dump file.

## Parameters

### `DumpFile` [in]

Specifies the name of the dump file to create. *DumpFile* must include the file name extension. *DumpFile* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started.

### `Qualifier` [in]

Specifies the type of dump file to create. For possible values, see [DEBUG_DUMP_XXX](https://learn.microsoft.com/previous-versions/ff541472(v=vs.85)).

### `FormatFlags` [in]

Specifies flags that determine the format of the dump file and--for user-mode minidumps--what information to include in the file. For details, see Remarks.

### `Comment` [in, optional]

Specifies a comment string to be included in the crash dump file. This string is displayed in the debugger console when the dump file is loaded. Some dump file formats do not support the storing of comment strings.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The DEBUG_FORMAT_*XXX* bit-flags are used by **WriteDumpFile2** and [WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide) to determine the format of a crash dump file and, for user-mode Minidumps, what information to include in the file.

The following bit-flags apply to all crash dump files.

| Value | Description |
| --- | --- |
| DEBUG_FORMAT_WRITE_CAB | Package the crash dump file in a CAB file. The supplied file name or file handle is used for the CAB file; the crash dump is first created in a temporary file before being moved into the CAB file. |
| DEBUG_FORMAT_CAB_SECONDARY_FILES | Include the current symbols and mapped images in the CAB file.<br><br>If DEBUG_FORMAT_WRITE_CAB is not set, this flag is ignored. |
| DEBUG_FORMAT_NO_OVERWRITE | Do not overwrite existing files. |

The following bit-flags can also be included for user-mode Minidumps.

| Value | Description |
| --- | --- |
| DEBUG_FORMAT_USER_SMALL_FULL_MEMORY | Add full memory data. All accessible committed pages owned by the target application will be included. |
| DEBUG_FORMAT_USER_SMALL_HANDLE_DATA | Add data about the handles that are associated with the target application. |
| DEBUG_FORMAT_USER_SMALL_UNLOADED_MODULES | Add unloaded module information. This information is available only in Windows Server 2003 and later versions of Windows. |
| DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY | Add indirect memory. A small region of memory that surrounds any address that is referenced by a pointer on the stack or backing store is included. |
| DEBUG_FORMAT_USER_SMALL_DATA_SEGMENTS | Add all data segments within the executable images. |
| DEBUG_FORMAT_USER_SMALL_FILTER_MEMORY | Set to zero all of the memory on the stack and in the backing store that is not useful for recreating the stack trace. This can make compression of the Minidump more efficient and increase privacy by removing unnecessary information. |
| DEBUG_FORMAT_USER_SMALL_FILTER_PATHS | Remove the module paths, leaving only the module names. This is useful for protecting privacy by hiding the directory structure (which may contain the user's name). |
| DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA | Add the process environment block (PEB) and thread environment block (TEB). This flag can be used to provide Windows system information for threads and processes. |
| DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY | Add all committed private read-write memory pages. |
| DEBUG_FORMAT_USER_SMALL_NO_OPTIONAL_DATA | Prevent privacy-sensitive data from being included in the Minidump. Currently, this flag excludes from the Minidump data that would have been added due to the following flags being set:<br><br>DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA,<br><br>DEBUG_FORMAT_USER_SMALL_FULL_MEMORY,<br><br>DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY,<br><br>DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY. |
| DEBUG_FORMAT_USER_SMALL_FULL_MEMORY_INFO | Add all basic memory information. This is the information returned by the [QueryVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces2-queryvirtual) method. The information for all memory is included, not just valid memory, which allows the debugger to reconstruct the complete virtual memory layout from the Minidump. |
| DEBUG_FORMAT_USER_SMALL_THREAD_INFO | Add additional thread information, which includes execution time, start time, exit time, start address, and exit status. |
| DEBUG_FORMAT_USER_SMALL_CODE_SEGMENTS | Add all code segments with the executable images. |

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[.dump (Create Dump File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-dump--create-dump-file-)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[WriteDumpFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfilewide)