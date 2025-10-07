# CanShareFolderW function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.\]

Used to determine whether to show the **Share this folder** option in web view.

## Parameters

*pszPath* \[in\]

Type: **LPCWSTR**

A pointer to a string that specifies the path of the folder to test.

## Return value

Type: **STDAPI**

Return values include the following.

| Return code/value | Description |
|------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|
| **S\_OK** | The path pointed to by *pszPath* specifies a folder that can be shared.<br> |
| **S\_FALSE** | The path pointed to by *pszPath* specifies a folder that cannot be shared.<br> |
| HRESULT error | An error has occurred.<br> |

## Remarks

This function has no associated .lib file. You must use [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to use it.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Ntshrui.dll |
| Unicode and ANSI names<br> | **CanShareFolderW** (Unicode)<br> |

## See also

[**ShowShareFolderUI**](https://learn.microsoft.com/windows/win32/shell/showsharefolderui)

