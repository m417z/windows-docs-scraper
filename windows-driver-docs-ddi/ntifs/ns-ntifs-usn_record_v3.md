## Description

The **USN_RECORD_V3** structure contains the information for an update sequence number (USN) change journal version 3.0 record. The version 2.0 record is defined by the [**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2) structure (also called **USN_RECORD** structure). See [USN_RECORD_V3 structure (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v3) for details.

## Members

### `RecordLength`

### `MajorVersion`

### `MinorVersion`

### `FileReferenceNumber`

### `ParentFileReferenceNumber`

### `Usn`

### `TimeStamp`

### `Reason`

### `SourceInfo`

### `SecurityId`

### `FileAttributes`

### `FileNameLength`

### `FileNameOffset`

### `FileName[1]`

## Remarks

## See also

[**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal)