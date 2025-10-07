# VarFileInfo structure

Represents the organization of data in a file-version resource. It contains version information not dependent on a particular language and code page combination.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of the entire **VarFileInfo** block, including all structures indicated by the **Children** member.

**wValueLength**

Type: **WORD**

This member is always equal to zero.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

The Unicode string L"VarFileInfo".

**Padding**

Type: **WORD**

As many zero words as necessary to align the **Children** member on a 32-bit boundary.

**Children**

Type: **[**Var**](https://learn.microsoft.com/windows/win32/menurc/var-str)**

Typically contains a list of languages that the application or DLL supports.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

The **Children** member of the [**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo) structure may contain zero or one **VarFileInfo** structures.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**Var**](https://learn.microsoft.com/windows/win32/menurc/var-str)

[**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

