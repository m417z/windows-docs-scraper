# PPROTECT\_FILE\_ENTRY structure

\[This structure is available for use in the operating systems specified in the Requirements section. Support for this structure was removed in Windows Vista and Windows Server 2008. Use the supported functions listed in [WRP Functions](https://learn.microsoft.com/windows/win32/wfp/wfp-functions) instead.\]

Structure used by the [**SfcGetFiles**](https://learn.microsoft.com/windows/win32/wfp/sfcgetfiles) function.

## Members

**SourceFileName**

Pointer to a string value containing the filename of the source file. This will be **NULL** if the file is not renamed on installation.

**FileName**

Pointer to string value containing the destination filename plus the full path to the file.

**InfName**

Pointer to string value containing the filename of the INF file which provides layout information. This parameter may be **NULL** when using the default layout.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Sfcfiles.h |

## See also

[**SfcGetFiles**](https://learn.microsoft.com/windows/win32/wfp/sfcgetfiles)

