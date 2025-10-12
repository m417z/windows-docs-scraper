# FM\_UNDELETE\_PROC function pointer

Specifies an application-defined callback function called by File Manager when the user chooses the **Undelete** command from the **File** menu.

## Parameters

*hwndOwner*

Type: **HWND**

The window handle to File Manager. An undelete DLL should use this handle to specify the owner window for any dialog box or message box the DLL might display.

*lpszDir*

Type: **LPSTR**

The address of a null-terminated string that contains the name of the initial directory.

## Return value

Type: **DWORD**

Returns one of the following values.

| Return code | Description |
|-----------------------------------------------------------------------------------------|--------------------------------------------------------------------|
| **-1** | An error occurred.<br> |
| **IDOK** | A file was undeleted. File Manager repaints its window.<br> |
| **IDCANCEL** | No file was undeleted.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

