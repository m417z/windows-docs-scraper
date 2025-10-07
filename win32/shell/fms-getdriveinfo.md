# FMS\_GETDRIVEINFO structure

Contains information about the drive selected in the active File Manager window (the directory window or the Search Results window).

## Members

**dwTotalSpace**

Type: **DWORD**

The total amount of storage space, in bytes, on the disk associated with the drive.

**dwFreeSpace**

Type: **DWORD**

The amount of free storage space, in bytes, on the disk associated with the drive.

**szPath**

Type: **TCHAR\[260\]**

the null-terminated path of the current directory.

**szVolume**

Type: **TCHAR\[14\]**

The null-terminated volume label of the disk associated with the drive.

**szShare**

Type: **TCHAR\[128\]**

The null-terminated name of the network resource (if the drive is being accessed through a network).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMExtensionProc**](https://learn.microsoft.com/windows/win32/shell/fmextensionproc)

[**FM\_GETDRIVEINFO**](https://learn.microsoft.com/windows/win32/shell/fm-getdriveinfo)

