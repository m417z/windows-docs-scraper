# DeltaFree function

Frees the specified memory block. You must call this function after successful calls to [CreateDeltaB](https://learn.microsoft.com/windows/win32/devnotes/msdelta-createdeltab) and [ApplyDeltaB](https://learn.microsoft.com/windows/win32/devnotes/msdelta-applydeltab) to free the MSDelta-allocated memory buffer.

## Parameters

*lpMemory*

[in] Memory block to be freed.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**. When the function returns **FALSE**, you can call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get the corresponding Win32 system error code.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| Header | msdelta.h |
| DLL | msdelta.dll |
| Unicode | Not applicable |

## See also

[MSDelta](https://learn.microsoft.com/windows/win32/devnotes/msdelta)

[CreateDeltaB](https://learn.microsoft.com/windows/win32/devnotes/msdelta-createdeltab)

[ApplyDeltaB](https://learn.microsoft.com/windows/win32/devnotes/msdelta-applydeltab)