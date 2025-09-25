# MFT_ENUM_DATA_V1 structure

## Description

Contains information defining the boundaries for and starting place of an enumeration of update
sequence number (USN) change journal records for ReFS volumes. It is used as the input buffer for the
[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data) control code.

## Members

### `StartFileReferenceNumber`

The ordinal position within the files on the current volume at which the enumeration is to begin.

The first call to [FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data) during an
enumeration must have the **StartFileReferenceNumber** member set to
`(DWORDLONG)0`. Each call to
**FSCTL_ENUM_USN_DATA** retrieves the starting point for
the subsequent call as the first entry in the output buffer. Subsequent calls must be made with
**StartFileReferenceNumber** set to this value. For more information, see
**FSCTL_ENUM_USN_DATA**.

### `LowUsn`

The lower boundary of the range of USN values used to filter which records are returned. Only records whose
last change journal USN is between or equal to the **LowUsn** and
**HighUsn** member values are returned.

### `HighUsn`

The upper boundary of the range of USN values used to filter which files are returned.

### `MinMajorVersion`

Indicates the minimum supported major version for the USN change journal.

### `MaxMajorVersion`

Indicates the maximum supported major version for the USN change journal.

| Value | Meaning |
| --- | --- |
| 2 | The data returned from the [FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data) control code will contain [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structures. |
| 3 | The data returned from the [FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data) control code will contain [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) or [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) structures. |

## See also

[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)