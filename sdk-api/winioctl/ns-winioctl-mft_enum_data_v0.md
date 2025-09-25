# MFT_ENUM_DATA_V0 structure

## Description

Contains information defining the boundaries for and starting place of an enumeration of update
sequence number (USN) change journal records. It is used as the input buffer for the
[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data) control code. Prior to
Windows Server 2012 this structure was named
**MFT_ENUM_DATA**. Use that name to compile with older SDKs
and compilers.

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

## See also

[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)