# DeleteExtractedFiles function

\[This function is no longer supported, so its behavior cannot be guaranteed.\]

The **DeleteExtractedFiles** function deletes the files that were extracted by the [**Extract**](https://learn.microsoft.com/windows/win32/devnotes/extract) function.

## Parameters

*ps*

A pointer to a [**SESSION**](https://learn.microsoft.com/windows/win32/devnotes/session) structure that contains information about the current session.

This function frees the memory in the **pFileList** member of this structure and sets **pFileList** to **NULL**.

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Cabinet.dll |

## See also

[**Extract**](https://learn.microsoft.com/windows/win32/devnotes/extract)

[**SESSION**](https://learn.microsoft.com/windows/win32/devnotes/session)

