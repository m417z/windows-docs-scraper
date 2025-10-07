# CharUpperBuffWrapW function

\[**CharUpperBuffWrapW** is available for use in Windows XP. It may not be available in subsequent versions. You should use [**CharUpperBuffW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-charupperbuffa) in its place.\]

Converts lowercase characters in a buffer to uppercase characters. The function converts the characters in place.

> [!Note]
> **CharUpperBuffWrapW** is a wrapper for the **CharUpperBuffW** function. See the [**CharUpperBuff**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-charupperbuffa) page for further usage notes.

## Parameters

*pch* \[in\]

Type: **LPWSTR**

A pointer to a buffer that contains one or more Unicode characters to process.

*cchLength* \[in\]

Type: **DWORD**

Specifies the size, in characters, of the buffer pointed to by *pch*.

## Return value

Type: **DWORD**

The number of characters processed.

## Remarks

The preferred method is to use [**CharUpperBuffW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-charupperbuffa) in conjunction with the Microsoft Layer for Unicode (MSLU).

**CharUpperBuffWrapW** must be called directly from Shlwapi.dll, using ordinal 44.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |

## See also

[**CharUpperBuff**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-charupperbuffa)

