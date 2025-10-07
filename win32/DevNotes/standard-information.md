# STANDARD\_INFORMATION structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Contains the standard information attribute. This attribute is present in every base file record and must be resident.

## Members

**Reserved**

Reserved.

**OwnerId**

The identifier of the file owner, from the security index.

**SecurityId**

The security identifier for the file.

## Remarks

Note that there is no associated header file for this structure.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

