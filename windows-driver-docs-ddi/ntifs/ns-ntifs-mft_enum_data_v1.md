## Description

The **MFT_ENUM_DATA_V1** structure contains information defining the boundaries for and starting place of an enumeration of update sequence number (USN) change journal records for ReFS volumes. It is used as the input buffer for the [**FSCTL_ENUM_USN_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_enum_usn_data) control code.

## Members

### `StartFileReferenceNumber`

The ordinal position within the files on the current volume at which the enumeration is to begin.

The first call to **FSCTL_ENUM_USN_DATA** during an enumeration must have the **StartFileReferenceNumber** member set to (DWORDLONG)0. Each call to **FSCTL_ENUM_USN_DATA** retrieves the starting point for the subsequent call as the first entry in the output buffer. Subsequent calls must be made with **StartFileReferenceNumber** set to this value.

### `LowUsn`

The lower boundary of the range of USN values used to filter which records are returned. Only records whose last change journal USN is between or equal to the LowUsn and HighUsn member values are returned.

### `HighUsn`

The upper boundary of the range of USN values used to filter which files are returned.

### `MinMajorVersion`

The minimum supported major version for the USN change journal.

### `MaxMajorVersion`

The maximum supported major version for the USN change journal.

| Value | Meaning |
| ----- | ------- |
| 2 | The data returned from FSCTL_ENUM_USN_DATA will contain USN_RECORD_V2 structures. |
| 3 | The data returned from FSCTL_ENUM_USN_DATA will contain USN_RECORD_V2 or USN_RECORD_V3 structures. |

## See also

[**FSCTL_ENUM_USN_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_enum_usn_data)