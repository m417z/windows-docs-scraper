## Description

The **USN_RECORD_COMMON_HEADER** structure contains the information for an update sequence number (USN) common header which is common through [**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2), [**USN_RECORD_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v3) and [**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4) structure.

## Members

### `RecordLength`

The total length of a record, in bytes.

Because USN record is a variable size, the **RecordLength** member should be used when calculating the address of the next record in an output buffer.

For [**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4) structure, the size in bytes of any change journal record is at most the size of the structure, plus (NumberOfExtents-1) times size of the USN_RECORD_EXTENT.

### `MajorVersion`

The major version number of the change journal software for this record.

For example, if the change journal software is version 4.0, the major version number is 4.

| Value | Description |
| ----- | ----------- |
| 2 | The structure is a [**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2) structure and the remainder of the structure should be parsed using that layout. |
| 3 | The structure is a [**USN_RECORD_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v3) structure and the remainder of the structure should be parsed using that layout. |
| 4 | The structure is a [**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4) structure and the remainder of the structure should be parsed using that layout. |

### `MinorVersion`

The minor version number of the change journal software for this record. For example, if the change journal software is version 4.0, the minor version number is zero.

## See also

[**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal)