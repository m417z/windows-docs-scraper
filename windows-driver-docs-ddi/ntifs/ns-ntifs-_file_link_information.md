# FILE_LINK_INFORMATION structure

## Description

The **FILE_LINK_INFORMATION** structure is used to create an NTFS hard link to an existing file.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ReplaceIfExists`

Set to TRUE to specify that if the link already exists, it should be replaced with the new link. Set to FALSE if the link creation operation should fail if the link already exists. Available starting with Windows 10, version 1809.

### `DUMMYUNIONNAME.Flags`

Flags for the link operation. This field is only applicable when used with the FileLinkInformationEx information class. Available starting with Windows 10, version 1809.

Here are the possible values:

| Value | Meaning |
| ----- | ------- |
| **FILE_LINK_REPLACE_IF_EXISTS** (0x00000001) | If a file with the given name already exists, it should be replaced with the new link. Equivalent to the ReplaceIfExists field used with the FileLinkInformation information class. |
| **FILE_LINK_POSIX_SEMANTICS** (0x00000002) | If FILE_LINK_REPLACE_IF_EXISTS is also specified, allow replacing a file even if there are existing handles to it. Existing handles to the replaced file continue to be valid for operations such as read and write. Any subsequent opens of the target name will open the new link, not the replaced file. |
| **FILE_LINK_SUPPRESS_STORAGE_RESERVE_INHERITANCE** (0x00000008) | When creating a link in a new directory, suppress any inheritance rules related to the storage reserve ID property of the file. |
| **FILE_LINK_NO_INCREASE_AVAILABLE_SPACE** (0x00000010) | If FILE_LINK_SUPPRESS_STORAGE_RESERVE_INHERITANCE is not also specified, when creating a link in a new directory, automatically resize affected storage reserve areas as needed to prevent the user visible free space on the volume from increasing. Requires manage volume access. |
| **FILE_LINK_NO_DECREASE_AVAILABLE_SPACE** (0x00000020) | If FILE_LINK_SUPPRESS_STORAGE_RESERVE_INHERITANCE is not also specified, when creating a link in a new directory, automatically resize affected storage reserve areas as needed to prevent the user visible free space on the volume from decreasing. Requires manage volume access. |
| **FILE_LINK_PRESERVE_AVAILABLE_SPACE** (0x00000030) | Equivalent to specifying both FILE_LINK_NO_INCREASE_AVAILABLE_SPACE and FILE_LINK_NO_DECREASE_AVAILABLE_SPACE. |
| **FILE_LINK_IGNORE_READONLY_ATTRIBUTE** (0x00000040) | If FILE_LINK_REPLACE_IF_EXISTS is also specified, allow replacing a file even if it is read-only. Requires WRITE_ATTRIBUTES access to the replaced file. |
| **FILE_LINK_FORCE_RESIZE_TARGET_SR** (0x00000080) | If FILE_LINK_SUPPRESS_STORAGE_RESERVE_INHERITANCE is not also specified, when creating a link in a new directory that is part of a different storage reserve area, always grow the target directory's storage reserve area by the full size of the file being linked. Requires manage volume access. |
| **FILE_LINK_FORCE_RESIZE_SOURCE_SR** (0x00000100) | If FILE_LINK_SUPPRESS_STORAGE_RESERVE_INHERITANCE is not also specified, when creating a link in a new directory that is part of a different storage reserve area, always shrink the source directory's storage reserve area by the full size of the file being linked. Requires manage volume access. |
| **FILE_LINK_FORCE_RESIZE_SR** (0x00000180) | Equivalent to specifying both FILE_LINK_FORCE_RESIZE_TARGET_SR and FILE_LINK_FORCE_RESIZE_SOURCE_SR. |

### `ReplaceIfExists`

Set to TRUE to specify that if the link already exists, it should be replaced with the new link. Set to FALSE if the link creation operation should fail if the link already exists.

### `RootDirectory`

If the link is to be created in the same directory as the file that is being linked to, or if the **FileName** member contains the full pathname for the link to be created, this is NULL. Otherwise it is a handle for the directory where the link is to be created.

### `FileNameLength`

Length, in bytes, of the file name string.

### `FileName[1]`

The first character of the name to be assigned to the newly created link. This is followed in memory by the remainder of the string. If the **RootDirectory** member is NULL and the link is to be created in a different directory from the file that is being linked to, this member specifies the full pathname for the link to be created. Otherwise, it specifies only the file name. (See the Remarks section for [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) for details on the syntax of this file name string.)

## Syntax

```cpp
typedef struct _FILE_LINK_INFORMATION {
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5)
    union {
        BOOLEAN ReplaceIfExists;  // FileLinkInformation
        ULONG Flags;              // FileLinkInformationEx
    } DUMMYUNIONNAME;
#else
    BOOLEAN ReplaceIfExists;
#endif
    HANDLE RootDirectory;
    ULONG FileNameLength;
    WCHAR FileName[1];
} FILE_LINK_INFORMATION, *PFILE_LINK_INFORMATION;

```

## Remarks

The **FILE_LINK_INFORMATION** structure is used to create an NTFS hard link to an existing file. This operation can be performed in either of the following ways:

* Call [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile) or [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), passing FileLinkInformation as the value of FileInformationClass and passing a caller-allocated, FILE_LINK_INFORMATION-structured buffer as the value of **FileInformation**. The **FileHandle** parameter specifies the existing file to which the hard link should point.

* Create an IRP with major function code IRP_MJ_SET_INFORMATION.

No specific access rights are required to set this information.

File system minifilters must use [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile), not [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), to set this information for a file.

For more information about NTFS hard links, see the Microsoft Windows SDK documentation for the Win32 **CreateHardLink** function.

The size of the **FileInformation** buffer passed to [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile) or [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) must be at least **sizeof**(FILE_LINK_INFORMATION).

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile)

[**IRP_MJ_SET_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)