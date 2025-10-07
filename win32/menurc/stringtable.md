# StringTable structure

Represents the organization of data in a file-version resource. It contains language and code page formatting information for the strings specified by the **Children** member. A code page is an ordered character set.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of this **StringTable** structure, including all structures indicated by the **Children** member.

**wValueLength**

Type: **WORD**

This member is always equal to zero.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

An 8-digit hexadecimal number stored as a Unicode string. The four most significant digits represent the language identifier. The four least significant digits represent the code page for which the data is formatted. Each Microsoft Standard Language identifier contains two parts: the low-order 10 bits specify the major language, and the high-order 6 bits specify the sublanguage. For a table of valid identifiers see .

**Padding**

Type: **WORD**

As many zero words as necessary to align the **Children** member on a 32-bit boundary.

**Children**

Type: **[**String**](https://learn.microsoft.com/windows/win32/menurc/string-str)**

An array of one or more [**String**](https://learn.microsoft.com/windows/win32/menurc/string-str) structures.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

The **Children** member of the [**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo) structure contains at least one **StringTable** structure.

Set the code page portion of the **szKey** member to the hexadecimal value 0x04b0 to indicate the Unicode code page, or to the hexadecimal value of the code page that is appropriate for the language component. After you choose the value for the code page you should continue to use the same value in later revisions to the file.

An executable file or DLL that supports multiple languages should have a version resource for each language, rather than a single version resource that contains strings in several languages. However, if you use the [**Var**](https://learn.microsoft.com/windows/win32/menurc/var-str) structure to list the languages that your application supports, the number of **StringTable** structures in the version resource is directly related to the number of language/code page identifier pairs in the **Value** member of the **Var** structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**String**](https://learn.microsoft.com/windows/win32/menurc/string-str)

[**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo)

[**Var**](https://learn.microsoft.com/windows/win32/menurc/var-str)

[**VarFileInfo**](https://learn.microsoft.com/windows/win32/menurc/varfileinfo)

[**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

