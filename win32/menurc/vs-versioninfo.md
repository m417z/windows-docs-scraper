# VS\_VERSIONINFO structure

Represents the organization of data in a file-version resource. It is the root structure that contains all other file-version information structures.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of the **VS\_VERSIONINFO** structure. This length does not include any padding that aligns any subsequent version resource data on a 32-bit boundary.

**wValueLength**

Type: **WORD**

The length, in bytes, of the **Value** member. This value is zero if there is no **Value** member associated with the current version structure.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

The Unicode string L"VS\_VERSION\_INFO".

**Padding1**

Type: **WORD**

Contains as many zero words as necessary to align the **Value** member on a 32-bit boundary.

**Value**

Type: **[**VS\_FIXEDFILEINFO**](https://learn.microsoft.com/windows/win32/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)**

Arbitrary data associated with this **VS\_VERSIONINFO** structure. The **wValueLength** member specifies the length of this member; if **wValueLength** is zero, this member does not exist.

**Padding2**

Type: **WORD**

As many zero words as necessary to align the **Children** member on a 32-bit boundary. These bytes are not included in **wValueLength**. This member is optional.

**Children**

Type: **WORD**

An array of zero or one [**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo) structures, and zero or one [**VarFileInfo**](https://learn.microsoft.com/windows/win32/menurc/varfileinfo) structures that are children of the current **VS\_VERSIONINFO** structure.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo)

[**VerQueryValue**](https://learn.microsoft.com/windows/desktop/api/Winver/nf-winver-verqueryvaluea)

[**VarFileInfo**](https://learn.microsoft.com/windows/win32/menurc/varfileinfo)

[**VS\_FIXEDFILEINFO**](https://learn.microsoft.com/windows/win32/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

