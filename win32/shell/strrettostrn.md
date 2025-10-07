# StrRetToStrN function

Takes an [**STRRET**](https://learn.microsoft.com/windows/desktop/api/Shtypes/ns-shtypes-strret) structure returned by [**IShellFolder::GetDisplayNameOf**](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof), converts it to a string, and places the result in a buffer.

## Parameters

*pszOut* \[out\]

Type: **LPTSTR**

Buffer to hold the display name. It will be returned as a null-terminated string. If *cchOut* is too small, the name will be truncated to fit.

*cchOut* \[in\]

Type: **UINT**

Size of *pszOut*, in characters. If *cchOut* is too small, the string will be truncated to fit.

*pStrRet* \[in, out\]

Type: **LPSTRRET**

Pointer to an [**STRRET**](https://learn.microsoft.com/windows/desktop/api/Shtypes/ns-shtypes-strret) structure. When the function returns, this pointer will no longer be valid.

*pidl* \[in\]

Type: **LPCITEMIDLIST**

Pointer to the item's [**ITEMIDLIST**](https://learn.microsoft.com/windows/desktop/api/Shtypes/ns-shtypes-itemidlist) structure.

## Return value

Type: **BOOL**

**TRUE** for success, **FALSE** for failure.

## Remarks

> [!Note]
> As of Shell32.dll version 5.0, calling this function is equivalent to calling [**StrRetToBuf**](https://learn.microsoft.com/windows/desktop/api/Shlwapi/nf-shlwapi-strrettobufa).

**StrRetToStrN** is not exported by name. To use it, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 96 from Shell32.dll to obtain a function pointer.

If the **uType** member of the structure pointed to by *pStrRet* is set to **STRRET\_WSTR**, the **pOleStr** member of that structure will be freed on return.

Note that this function is exported from Shell32.dll rather than Shlwapi.dll. It is also included in Shlobj.h rather than Shlwapi.h.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll (version 4.71 or later) |

## See also

[**StrRetToStr**](https://learn.microsoft.com/windows/desktop/api/Shlwapi/nf-shlwapi-strrettostra)

[**StrRetToBuf**](https://learn.microsoft.com/windows/desktop/api/Shlwapi/nf-shlwapi-strrettobufa)

