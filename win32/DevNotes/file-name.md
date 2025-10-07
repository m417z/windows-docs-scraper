# FILE\_NAME structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Represents a file name attribute. A file has one file name attribute for every directory it is entered into.

## Members

**ParentDirectory**

A file reference to the directory that indexes to this name. See [**MFT\_SEGMENT\_REFERENCE**](https://learn.microsoft.com/windows/win32/devnotes/mft-segment-reference).

**Reserved**

Reserved.

**FileNameLength**

The length of the file name, in Unicode characters.

**Flags**

The file name flags.

**FILE\_NAME\_NTFS** (0x01)

**FILE\_NAME\_DOS** (0x02)

**FileName**

The first character of the file name.

## Remarks

Note that there is no associated header file for this structure.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

