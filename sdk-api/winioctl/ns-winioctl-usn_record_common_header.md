# USN_RECORD_COMMON_HEADER structure

## Description

Contains the information for an update sequence number (USN) common header which is common through [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2), [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) and [USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4).

## Members

### `RecordLength`

The total length of a record, in bytes.

Because USN record is a variable size, the **RecordLength** member should be used when calculating the address of the next record in an output buffer, for example, a buffer that is returned from operations for the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function that work with different USN record types.

For [USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4), the size in bytes of any change journal record is at most the size of the structure, plus (NumberOfExtents-1) times size of the [USN_RECORD_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_extent).

### `MajorVersion`

The major version number of the change journal software for this record.

For example, if the change journal software is version 4.0, the major version number is 4.

| Value | Description |
| --- | --- |
| 2 | The structure is a [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structure and the remainder of the structure should be parsed using that layout. |
| 3 | The structure is a [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) structure and the remainder of the structure should be parsed using that layout. |
| 4 | The structure is a [USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4) and the remainder of the structure should be parsed using that layout. |

### `MinorVersion`

The minor version number of the change journal software for this record. For example, if the change journal software is version 4.0, the minor version number is zero.

## See also

[USN_RECORD_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_extent)

[USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3)

[USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)