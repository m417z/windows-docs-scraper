# CryptUIDlgViewSignerInfo function

\[The **CryptUIDlgViewSignerInfo** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. \]

The **CryptUIDlgViewSignerInfo** function displays a dialog box that contains the signer information for a signed message.

> [!Note]
> This function is not declared in a published header file. To use this structure, declare it in the exact format shown.

## Parameters

*pcvsi* \[in\]

A pointer to a [**CRYPTUI\_VIEWSIGNERINFO\_STRUCT**](https://learn.microsoft.com/windows/win32/seccrypto/cryptui-viewsignerinfo-struct) structure that contains the signer information to display.

## Return value

This function returns a nonzero value on success and zero on failure. For extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

Possible error codes returned from [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) include, but are not limited to, the following.

| Return code | Description |
|-----------------------------------------------------------------------------------------------|--------------------------------------------------|
| **E\_INVALIDARG** | One or more arguments are not valid.<br> |
| **E\_OUTOFMEMORY** | A memory allocation failure occurred.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of support<br> | Windows 7 \[desktop apps only\]<br> |
| Library<br> | Cryptui.lib |
| DLL<br> | Cryptui.dll |
| Unicode and ANSI names<br> | **CryptUIDlgViewSignerInfoW** (Unicode) and **CryptUIDlgViewSignerInfoA** (ANSI)<br> |

## See also

[**CRYPTUI\_VIEWSIGNERINFO\_STRUCT**](https://learn.microsoft.com/windows/win32/seccrypto/cryptui-viewsignerinfo-struct)