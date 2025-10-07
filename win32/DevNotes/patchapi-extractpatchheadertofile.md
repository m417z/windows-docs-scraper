# ExtractPatchHeaderToFileA/W function

The **ExtractPatchHeaderToFileA** and **ExtractPatchHeaderToFileW** functions extract the header information from a delta. The delta is provided as a file path. The output header is also written to a provided path.

## Parameters

*PatchFileName*

The name of the delta containing the header.

*PatchHeaderFileName*

The name of the header file that is to be created.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| Header | patchapi.h |
| DLL | mspatchc.dll |
| Unicode | Implemented as ExtractPatchHeaderToFileW (Unicode) and ExtractPatchHeaderToFileA (ANSI) |

## See also

[PatchAPI](https://learn.microsoft.com/windows/win32/devnotes/patchapi)