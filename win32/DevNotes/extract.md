# Extract function

\[This function is no longer supported, so its behavior cannot be guaranteed.\]

The **Extract** function extracts files from a cabinet.

## Parameters

*ps*

Pointer to a [**SESSION**](https://learn.microsoft.com/windows/win32/devnotes/session) structure that contains information about the current session.

*lpCabName*

Pointer to the name of the cabinet from which files are to be extracted.

## Return value

If the function succeeds, it returns **S\_OK**; otherwise, it returns an error code.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Cabinet.dll |

## See also

[**DeleteExtractedFiles**](https://learn.microsoft.com/windows/win32/devnotes/deleteextractedfiles)

[**ERF**](https://learn.microsoft.com/windows/win32/api/fdi_fci_types/ns-fdi_fci_types-erf)

[**SESSION**](https://learn.microsoft.com/windows/win32/devnotes/session)

