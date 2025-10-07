# Str\_GetPtr function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.\]

Copies a string from one buffer to another.

## Parameters

*pszSource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a source string.

*pszDest* \[in, out\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the destination buffer. This value can be **NULL**.

*cchDest* \[in\]

Type: **int**

The size of *pszDest*, in characters.

## Return value

Type: **int**

If *pszDest* is **NULL** or *cchDest* is zero, returns the size of the buffer, in characters, needed to contain a null-terminated copy of the string pointed to by *pszSource*.

If *pszDest* is non-**NULL**, returns the number of characters successfully copied, including the terminating null character.

If *pszDest* cannot hold the entire string pointed to by *pszSource*, then (*cchDest*-1) characters are copied, the string null-terminated, and *cchDest* returned.

## Remarks

**Str\_GetPtr** is available as ANSI (**Str\_GetPtrA**) and Unicode (**Str\_GetPtrW**) versions. These functions are not exported by name or declared in a public header file. To use them, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 233 (**Str\_GetPtrA**) or 235 (**Str\_GetPtrW**) from ComCtl32.dll to obtain a function pointer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | ComCtl32.dll |
| Unicode and ANSI names<br> | **Str\_GetPtrW** (Unicode) and **Str\_GetPtrA** (ANSI)<br> |

