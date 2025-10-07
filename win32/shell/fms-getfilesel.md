# FMS\_GETFILESEL structure

Contains information about a selected file in the active File Manager window (the directory window or the Search Results window).

## Members

**ftTime**

Type: **FILETIME**

The time and date the file was created.

**dwSize**

Type: **DWORD**

The size, in bytes, of the file.

**bAttr**

Type: **BYTE**

The attributes of the file.

**szName**

Type: **TCHAR**

The null-terminated full path and file name of the selected file.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMExtensionProc**](https://learn.microsoft.com/windows/win32/shell/fmextensionproc)

