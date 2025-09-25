# FAT_STATISTICS structure

## Description

Contains statistical information from the FAT file system.

## Members

### `CreateHits`

The number of create operations.

### `SuccessfulCreates`

The number of successful create operations.

### `FailedCreates`

The number of failed create operations.

### `NonCachedReads`

The number of read operations that were not cached.

### `NonCachedReadBytes`

The number of bytes read from a file that were not cached.

### `NonCachedWrites`

The number of write operations that were not cached.

### `NonCachedWriteBytes`

The number of bytes written to a file that were not cached.

### `NonCachedDiskReads`

The number of read operations that were not cached. This value includes sub-read operations.

### `NonCachedDiskWrites`

The number of write operations that were not cached. This value includes sub-write operations.

## See also

[EXFAT_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-exfat_statistics)

[FILESYSTEM_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-filesystem_statistics)