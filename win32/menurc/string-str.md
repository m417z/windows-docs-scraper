# String structure

Represents the organization of data in a file-version resource. It contains a string that describes a specific aspect of a file, for example, a file's version, its copyright notices, or its trademarks.

## Members

**wLength**

Type: **WORD**

The length, in bytes, of this **String** structure.

**wValueLength**

Type: **WORD**

The size, in words, of the **Value** member.

**wType**

Type: **WORD**

The type of data in the version resource. This member is 1 if the version resource contains text data and 0 if the version resource contains binary data.

**szKey**

Type: **WCHAR**

An arbitrary Unicode string. The **szKey** member can be one or more of the following values. These values are guidelines only.

**Comments**

The **Value** member contains any additional information that should be displayed for diagnostic purposes. This string can be an arbitrary length.

**CompanyName**

The **Value** member identifies the company that produced the file. For example, "Microsoft Corporation" or "Standard Microsystems Corporation, Inc."

**FileDescription**

The **Value** member describes the file in such a way that it can be presented to users. This string may be presented in a list box when the user is choosing files to install. For example, "Keyboard driver for AT-style keyboards" or "Microsoft Word for Windows".

**FileVersion**

The **Value** member identifies the version of this file. For example, **Value** could be "3.00A" or "5.00.RC2".

**InternalName**

The **Value** member identifies the file's internal name, if one exists. For example, this string could contain the module name for a DLL, a virtual device name for a Windows virtual device, or a device name for a MS-DOS device driver.

**LegalCopyright**

The **Value** member describes all copyright notices, trademarks, and registered trademarks that apply to the file. This should include the full text of all notices, legal symbols, copyright dates, trademark numbers, and so on. In English, this string should be in the format "Copyright Microsoft Corp. 1990 1994".

**LegalTrademarks**

The **Value** member describes all trademarks and registered trademarks that apply to the file. This should include the full text of all notices, legal symbols, trademark numbers, and so on. In English, this string should be in the format "Windows is a trademark of Microsoft Corporation".

**OriginalFilename**

The **Value** member identifies the original name of the file, not including a path. This enables an application to determine whether a file has been renamed by a user. This name may not be MS-DOS 8.3-format if the file is specific to a non-FAT file system.

**PrivateBuild**

The **Value** member describes by whom, where, and why this private version of the file was built. This string should only be present if the **VS\_FF\_PRIVATEBUILD** flag is set in the **dwFileFlags** member of the [**VS\_FIXEDFILEINFO**](https://learn.microsoft.com/windows/win32/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure. For example, **Value** could be "Built by OSCAR on \\OSCAR2".

**ProductName**

The **Value** member identifies the name of the product with which this file is distributed. For example, this string could be "Microsoft Windows".

**ProductVersion**

The **Value** member identifies the version of the product with which this file is distributed. For example, **Value** could be "3.00A" or "5.00.RC2".

**SpecialBuild**

The **Value** member describes how this version of the file differs from the normal version. This entry should only be present if the **VS\_FF\_SPECIALBUILD** flag is set in the **dwFileFlags** member of the [**VS\_FIXEDFILEINFO**](https://learn.microsoft.com/windows/win32/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure. For example, **Value** could be "Private build for Olivetti solving mouse problems on M250 and M250E computers".

**Padding**

Type: **WORD**

As many zero words as necessary to align the **Value** member on a 32-bit boundary.

**Value**

Type: **WORD**

A zero-terminated string. See the **szKey** member description for more information.

## Remarks

This structure is not a true C-language structure because it contains variable-length members. This structure was created solely to depict the organization of data in a version resource and does not appear in any of the header files shipped with the Windows Software Development Kit (SDK).

A **String** structure may have an **szKey** value of, for example, "CompanyName" and a **Value** of "Microsoft Corporation". Another **String** structure with the same **szKey** value could contain a **Value** of "Microsoft GmbH". This might occur if the second **String** structure were associated with a [**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable) structure whose **szKey** value is 040704b0 that is, German/Unicode.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**StringTable**](https://learn.microsoft.com/windows/win32/menurc/stringtable)

[**VS\_FIXEDFILEINFO**](https://learn.microsoft.com/windows/win32/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)

[**StringFileInfo**](https://learn.microsoft.com/windows/win32/menurc/stringfileinfo)

[**VS\_VERSIONINFO**](https://learn.microsoft.com/windows/win32/menurc/vs-versioninfo)

**Conceptual**

[Version Information](https://learn.microsoft.com/windows/win32/menurc/version-information)

