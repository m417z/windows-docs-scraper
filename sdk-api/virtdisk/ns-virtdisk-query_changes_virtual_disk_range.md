# QUERY_CHANGES_VIRTUAL_DISK_RANGE structure

## Description

Identifies an area on a virtual hard disk (VHD) that has changed as tracked by resilient change tracking (RCT).

## Members

### `ByteOffset`

The distance from the start of the virtual disk to the beginning of the area of the virtual disk that has changed, in bytes.

### `ByteLength`

The length of the area of the virtual disk that has changed, in bytes.

### `Reserved`

Reserved.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[QueryChangesVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-querychangesvirtualdisk)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))