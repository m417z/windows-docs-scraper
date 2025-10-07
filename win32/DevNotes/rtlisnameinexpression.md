# RtlIsNameInExpression function

Determines whether a Unicode string matches the specified pattern.

## Parameters

*Expression* \[in\]

A pointer to the pattern string. This string can contain wildcard characters. If the *IgnoreCase* parameter is TRUE, the string must contain only uppercase characters.

*Name* \[in\]

A pointer to the string to be compared against the pattern. This string cannot contain wildcard characters.

*IgnoreCase* \[in\]

**TRUE** for case-insensitive matching, or **FALSE** for case-sensitive matching.

*UpcaseTable* \[in, optional\]

An optional pointer to an uppercase character table to use for case-insensitive matching. If this parameter is NULL, the default system uppercase character table is used.

## Return value

Returns **TRUE** if the string matches the pattern. If the string does not match the pattern, this function returns **FALSE**.

## Remarks

This function has no associated header file. The associated import library, Ntdll.lib, is available in the Microsoft Windows Driver Kit (WDK). You can also call this function using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| DLL<br> | Ntdll.dll |

