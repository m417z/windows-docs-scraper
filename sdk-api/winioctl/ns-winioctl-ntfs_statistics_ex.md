# NTFS_STATISTICS_EX structure

## Description

Contains statistical information from the NTFS file system.Support for this structure started with Windows 10.

## Members

### `LogFileFullExceptions`

The number of exceptions generated due to the log file being full.

### `OtherExceptions`

The number of other exceptions generated.

### `MftReads`

The number of read operations on the master file table (MFT).

### `MftReadBytes`

The number of bytes read from the MFT.

### `MftWrites`

The number of write operations on the MFT.

### `MftWriteBytes`

The number of bytes written to the MFT.

### `MftWritesUserLevel`

### `MftWritesUserLevel.Write`

The number of MFT writes due to a write operation.

### `MftWritesUserLevel.Create`

The number of MFT writes due to a create operation.

### `MftWritesUserLevel.SetInfo`

The number of MFT writes due to setting file information.

### `MftWritesUserLevel.Flush`

The number of MFT writes due to a flush operation.

### `MftWritesFlushForLogFileFull`

The number of flushes of the MFT performed because the log file was full.

### `MftWritesLazyWriter`

The number of MFT write operations performed by the lazy writer thread.

### `MftWritesUserRequest`

Reserved.

### `Mft2Writes`

The number of write operations on the MFT mirror.

### `Mft2WriteBytes`

The number of bytes written to the MFT mirror.

### `Mft2WritesUserLevel`

### `Mft2WritesUserLevel.Write`

The number of MFT mirror writes due to a write operation.

### `Mft2WritesUserLevel.Create`

The number of MFT mirror writes due to a create operation.

### `Mft2WritesUserLevel.SetInfo`

The number of MFT mirror writes due to setting file information.

### `Mft2WritesUserLevel.Flush`

The number of MFT mirror writes due to a flush operation.

### `Mft2WritesFlushForLogFileFull`

The number of flushes of the MFT mirror performed because the log file was full.

### `Mft2WritesLazyWriter`

The number of MFT mirror write operations performed by the lazy writer thread.

### `Mft2WritesUserRequest`

Reserved.

### `RootIndexReads`

The number of read operations on the root index.

### `RootIndexReadBytes`

The number of bytes read from the root index.

### `RootIndexWrites`

The number of write operations on the root index.

### `RootIndexWriteBytes`

The number of bytes written to the root index.

### `BitmapReads`

The number of read operations on the cluster allocation bitmap.

### `BitmapReadBytes`

The number of bytes read from the cluster allocation bitmap.

### `BitmapWrites`

The number of write operations on the cluster allocation bitmap.

### `BitmapWriteBytes`

The number of bytes written to the cluster allocation bitmap.

### `BitmapWritesFlushForLogFileFull`

The number of flushes of the bitmap performed because the log file was full.

### `BitmapWritesLazyWriter`

The number of bitmap write operations performed by the lazy writer thread.

### `BitmapWritesUserRequest`

Reserved.

### `BitmapWritesUserLevel`

### `BitmapWritesUserLevel.Write`

The number of bitmap writes due to a write operation.

### `BitmapWritesUserLevel.Create`

The number of bitmap writes due to a create operation.

### `BitmapWritesUserLevel.SetInfo`

The number of bitmap writes due to setting file information.

### `BitmapWritesUserLevel.Flush`

The number of bitmap writes due to a flush operation.

### `MftBitmapReads`

The number of read operations on the MFT bitmap.

### `MftBitmapReadBytes`

The number of bytes read from the MFT bitmap.

### `MftBitmapWrites`

The number of write operations on the MFT bitmap.

### `MftBitmapWriteBytes`

The number of bytes written to the MFT bitmap.

### `MftBitmapWritesFlushForLogFileFull`

The number of flushes of the MFT bitmap performed because the log file was full.

### `MftBitmapWritesLazyWriter`

The number of MFT bitmap write operations performed by the lazy writer thread.

### `MftBitmapWritesUserRequest`

Reserved.

### `MftBitmapWritesUserLevel`

### `MftBitmapWritesUserLevel.Write`

The number of MFT bitmap writes due to a write operation.

### `MftBitmapWritesUserLevel.Create`

The number of bitmap writes due to a create operation.

### `MftBitmapWritesUserLevel.SetInfo`

The number of bitmap writes due to setting file information.

### `MftBitmapWritesUserLevel.Flush`

The number of bitmap writes due to a flush operation.

### `UserIndexReads`

The number of read operations on the user index.

### `UserIndexReadBytes`

The number of bytes read from the user index.

### `UserIndexWrites`

The number of write operations on the user index.

### `UserIndexWriteBytes`

The number of bytes written to the user index.

### `LogFileReads`

The number of read operations on the log file.

### `LogFileReadBytes`

The number of bytes read from the log file.

### `LogFileWrites`

The number of write operations on the log file.

### `LogFileWriteBytes`

The number of bytes written to the log file.

### `Allocate`

### `Allocate.Calls`

The number of individual calls to allocate clusters.

### `Allocate.RunsReturned`

The number of runs used to satisfy all the requests.

### `Allocate.Hints`

The number of times a hint was specified.

### `Allocate.HintsHonored`

The number of times the hint was useful.

### `Allocate.Cache`

The number of times the cache was useful other than the hint.

### `Allocate.CacheMiss`

The number of times the cache was not useful.

### `Allocate.Clusters`

The number of clusters allocated.

### `Allocate.HintsClusters`

The number of clusters allocated through the hint.

### `Allocate.CacheClusters`

The number of clusters allocated through the cache other than the hint.

### `Allocate.CacheMissClusters`

The number of clusters allocated without the cache.

### `DiskResourcesExhausted`

The number of failed attempts made to acquire a slab of storage for use on the current thinly provisioned volume.

### `VolumeTrimCount`

The number of volume level trim operations issued.

### `VolumeTrimTime`

The total time elapsed during all volume level trim operations. This value, divided by the frequency value from [QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency) or [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter), will give the time in seconds.

### `VolumeTrimByteCount`

The total number of bytes issued by all volume level trim operations.

### `FileLevelTrimCount`

The number of file level trim operations issued.

### `FileLevelTrimTime`

The total time elapsed during all file level trim operations. This value, divided by the frequency value from [QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency) or [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter), will give the time in seconds.

### `FileLevelTrimByteCount`

The total number of bytes issued by all file level trim operations.

### `VolumeTrimSkippedCount`

The number of times a volume level trim operation was aborted before being sent down through the storage stack.

### `VolumeTrimSkippedByteCount`

The number of bytes that were not sent through a volume level trim operation because they were skipped.

### `NtfsFillStatInfoFromMftRecordCalledCount`

### `NtfsFillStatInfoFromMftRecordBailedBecauseOfAttributeListCount`

### `NtfsFillStatInfoFromMftRecordBailedBecauseOfNonResReparsePointCount`

## Remarks

The MFT, MFT mirror, root index, user index, bitmap, and MFT bitmap are counted as metadata files. The log
file is not counted as a metadata file.

The number of read and write operations measured is the number of paging operations.

## See also

[FILESYSTEM_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-filesystem_statistics)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter)

[QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency)