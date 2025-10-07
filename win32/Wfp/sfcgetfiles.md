# SfcGetFiles function

\[This function is available for use in the operating systems specified in the Requirements section. Support for this function was removed in Windows Vista and Windows Server 2008. Use the supported functions listed in [WRP Functions](https://learn.microsoft.com/windows/win32/wfp/wfp-functions) instead.\]

Lists protected files.

## Parameters

*ProtFileData* \[out\]

A pointer to a [**PPROTECT\_FILE\_ENTRY**](https://learn.microsoft.com/windows/win32/wfp/pprotect-file-entry) structure that contains the protected files list.

*FileCount* \[out\]

A pointer to a location containing a ULONG value that is the number of protected files.

## Return value

If the function succeeds, the return value is STATUS\_SUCCESS. If the function fails, it returns the appropriate NTSTATUS error code.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Sfcfiles.h |
| DLL<br> | Sfcfiles.dll |

## See also

[**PPROTECT\_FILE\_ENTRY**](https://learn.microsoft.com/windows/win32/wfp/pprotect-file-entry)

