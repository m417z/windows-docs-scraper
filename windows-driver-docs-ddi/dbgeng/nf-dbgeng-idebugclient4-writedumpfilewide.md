# IDebugClient4::WriteDumpFileWide

## Description

The **WriteDumpFileWide** method creates a user-mode or kernel-modecrash dump file.

## Parameters

### `FileName` [in, optional]

Specifies the name of the dump file to create. *FileName* must include the file name extension. *FileName* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. If *FileHandle* is not **NULL**, *FileName* is ignored (except when writing status messages to the debugger console).

### `FileHandle` [in]

Specifies the file handle of the file to write the crash dump to. If *FileHandle* is **NULL**, the file specified in *FileName* is used instead.

### `Qualifier` [in]

Specifies the type of dump to create. For possible values, see [DEBUG_DUMP_XXX](https://learn.microsoft.com/previous-versions/ff541472(v=vs.85)).

### `FormatFlags` [in]

Specifies flags that determine the format of the dump file and--for user-mode minidumps--what information to include in the file. For details, see [DEBUG_FORMAT_XXX](https://learn.microsoft.com/previous-versions/ff541497(v=vs.85)).

### `Comment` [in, optional]

Specifies a comment string to be included in the crash dump file. This string is displayed in the debugger console when the dump file is loaded.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[.dump (Create Dump File)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-dump--create-dump-file-)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[WriteDumpFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-writedumpfile2)