# IDebugClient8::OpenDumpFileWide2

## Description

The **OpenDumpFileWide2** method opens a dump file as a debugger target.

## Parameters

### `FileName` [in, optional]

Specifies the name of the dump file to open -- unless *FileHandle* is not zero, in which case *FileName* is used only when the engine is queried for the name of the dump file. *FileName* must include the file name extension. *FileName* can include a relative or absolute path; relative paths are relative to the directory in which the debugger was started. *FileName* can also be in the form of a file URL, starting with "file://". If *FileName* specifies a cabinet (.cab) file, the cabinet file is searched for the first file with extension .kdmp, then .hdmp, then .mdmp, and finally .dmp.

### `FileHandle` [in]

Specifies the file handle of the dump file to open. If *FileHandle* is zero, *FileName* is used to open the dump file. Otherwise, if *FileName* is not **NULL**, the engine returns it when queried for the name of the dump file. If *FileHandle* is not zero and *FileName* is **NULL**, the engine will return **HandleOnly** for the file name.

### `AlternateArch` [in]

Specifies the AlternateArch argument which is an IMAGE_FILE_MACHINE_* constant. For more information, see [Image File Machine Constants](https://learn.microsoft.com/windows/win32/sysinfo/image-file-machine-constants).

These two constants are supported.

- IMAGE_FILE_MACHINE_AMD64: Load as if the image is running in an x64 process

- IMAGE_FILE_MACHINE_ARM64: Load as if the image is running in an ARM64 process

This parameter is only relevant if you are using OpenDumpFileWide2 to open an image file (not a dump file) which can be mapped into different architectures. For example ARM64X, where the DLL can be loaded into an x64/EC process or an ARM64 process.

By default, information about the DLL is presented using whatever architecture the image headers have defined. If you call OpenDumpFileWide2 with a different architecture, the information will be presented using the architecture that was passed. This allows you to see the “fixups” which the OS would have applied if the DLL were loaded into that architecture of process.

For more information about ARM64X, see [Arm64X PE files](https://learn.microsoft.com/windows/arm/arm64x-pe).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The engine doesn't completely attach to the dump file until the WaitForEvent method has been called. When a dump file is created from a process or kernel, information about the last event is stored in the dump file. After the dump file is opened, the next time execution is attempted, the engine will generate this event for the event callbacks. Only then does the dump file become available in the debugging session.
For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[DEBUG_CLIENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_client_context)

[IDebugClient8](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient8)