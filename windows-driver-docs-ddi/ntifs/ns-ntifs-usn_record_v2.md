## Description

The **USN_RECORD_V2** structure contains the information for an update sequence number (USN) change journal version 2.0 record. See [USN_RECORD_V2 structure (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v2) for details.

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