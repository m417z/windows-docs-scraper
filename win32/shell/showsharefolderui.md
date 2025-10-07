# ShowShareFolderUI function

Displays the **Folder Sharing** tab on the properties sheet for the specified folder.

## Parameters

*hwndParent* \[in\]

Type: **HWND**

A handle to the parent window for the property sheet.

*pszPath* \[in\]

Type: **LPCWSTR**

A pointer to a string that specifies the path to the folder that displays its **Folder Sharing** tab.

## Return value

Type: **HRESULT**

This function always returns S\_OK.

## Remarks

This function has no associated .lib file. You must use [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to use it.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Ntshrui.dll |
| Unicode and ANSI names<br> | **ShowShareFolderUIW** (Unicode)<br> |

## See also

[**CanShareFolderW**](https://learn.microsoft.com/windows/win32/shell/cansharefolderw)

