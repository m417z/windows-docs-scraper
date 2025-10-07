# StringFileInfo structure

Represents the organization of data in a file-version resource. It contains version information that can be displayed for a particular language and code page.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of the entire **StringFileInfo** block, including all structures indicated by the **Children** member.

**wValueLength**

Type: **WORD**

This member is always equal to zero.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

The Unicode string L"StringFileInfo".

**Padding**

Type: **WORD**

As many zero words as necessary to align the **Children** member on a 32-bit boundary.

**Children**

Type: **[**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable)**

An array of one or more [**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable) structures. Each **StringTable** structure's **szKey** member indicates the appropriate language and code page for displaying the text in that **StringTable** structure.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

The **Children** member of the [**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo) structure may contain zero or more **StringFileInfo** structures.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable)

[**String**](https://learn.microsoft.com/windows/win32/menurc/string-str)

[**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

