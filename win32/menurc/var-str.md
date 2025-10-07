# Var structure

Represents the organization of data in a file-version resource. It typically contains a list of language and code page identifier pairs that the version of the application or DLL supports.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of the **Var** structure.

**wValueLength**

Type: **WORD**

The length, in bytes, of the **Value** member.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

The Unicode string L"Translation".

**Padding**

Type: **WORD**

As many zero words as necessary to align the **Value** member on a 32-bit boundary.

**Value**

Type: **DWORD**

An array of one or more values that are language and code page identifier pairs. For additional information, see the following Remarks section.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

If you use the **Var** structure to list the languages your application or DLL supports instead of using multiple version resources, use the **Value** member to contain an array of **DWORD** values indicating the language and code page combinations supported by this file. The low-order word of each **DWORD** must contain a Microsoft language identifier, and the high-order word must contain the IBM code page number. Either high-order or low-order word can be zero, indicating that the file is language or code page independent. If the **Var** structure is omitted, the file will be interpreted as both language and code page independent.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**VarFileInfo**](https://learn.microsoft.com/windows/win32/menurc/varfileinfo)

[**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo)

[**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable)

[**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

