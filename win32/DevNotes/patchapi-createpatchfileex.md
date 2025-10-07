# CreatePatchFileExA/W function

The **CreatePatchFileExA** and **CreatePatchFileExW** functions create a delta between the specified source file and the specified target file. Both the source and the target files are provided as paths. The output delta is also written to a provided path. These functions provide progress reporting during the create process.

## Parameters

*OldFileCount*

The total number of source files. Used to create deltas against multiple source files (maximum 255).

*OldFileInfoArray*

Pointer to source file information array.

*NewFileName*

The name of the target file.

*PatchFileName*

The name of the delta that is created.

*OptionFlags*

Creation flags.

*ProgressCallback*

Pointer to application-defined progress callback.

*CallbackContext*

Pointer to application-defined context.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| Header | patchapi.h |
| DLL | mspatchc.dll |
| Unicode | Implemented as CreatePatchFileExW (Unicode) and CreatePatchFileExA (ANSI) |

## See also

[PatchAPI](https://learn.microsoft.com/windows/win32/devnotes/patchapi)