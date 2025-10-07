# STORAGE\_READ\_CAPACITY structure

Contains information about the size of a device. This is returned from the [**IOCTL\_STORAGE\_READ\_CAPACITY**](https://learn.microsoft.com/windows/desktop/api/WinIoCtl/ni-winioctl-ioctl_storage_read_capacity) control code.

## Members

**Version**

The version of this structure. The caller must set this member to `sizeof(STORAGE_READ_CAPACITY)`.

**Size**

The size of the data returned.

**BlockLength**

The number of bytes per block.

**NumberOfBlocks**

The total number of blocks on the disk.

**DiskLength**

The disk size in bytes.

## Remarks

The header file Ntddstor.h is available in the Windows Driver Kit (WDK).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008, Windows Server 2003 with SP1<br> |
| Header<br> | Ntddstor.h |

## See also

[**IOCTL\_STORAGE\_READ\_CAPACITY**](https://learn.microsoft.com/windows/desktop/api/WinIoCtl/ni-winioctl-ioctl_storage_read_capacity)

