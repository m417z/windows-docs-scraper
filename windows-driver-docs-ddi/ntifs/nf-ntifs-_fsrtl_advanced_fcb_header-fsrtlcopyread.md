# FsRtlCopyRead function

## Description

The **FsRtlCopyRead** routine copies data from a cached file to a user buffer.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file from which the data is to be read.

### `FileOffset` [in]

Starting byte offset within the cached file.

### `Length` [in]

Length in bytes of the data to be read.

### `Wait` [in]

Set to TRUE if the caller can be put into a wait state until all the data has been copied, FALSE otherwise.

### `LockKey` [in]

A value that is associated with the byte range to lock. If the range to lock overlaps another range that is already locked with a nonexclusive lock, or if the range to read is a subrange of another range that is already locked nonexclusively, the value in this parameter must be the key for that nonexclusive lock The lock must be held by the parent process of the calling thread. Otherwise, this parameter has no effect.

### `Buffer` [out]

Pointer to a buffer into which the data is to be copied.

### `IoStatus` [out]

Pointer to a caller-allocated structure that receives the final completion status and information about the operation. If the data is copied successfully, **IoStatus.Status** contains STATUS_SUCCESS. If not all of the data is copied successfully, **IoStatus.Information** contains the actual number of bytes that were copied.

### `DeviceObject` [in]

The device object for the device that holds the file data.

## Return value

**FsRtlCopyRead** returns TRUE if the copy request was completed, FALSE otherwise. Note that a return value of TRUE does not necessarily mean that the copy operation was successful.

If **FsRtlCopyRead** returns FALSE, or if the contents of **IoStatus** indicate that the copy operation failed, the caller must allocate a read IRP instead of calling **FsRtlCopyRead**.

## Remarks

Rather than implementing a file-system-specific fast I/O read routine, developers of file systems that support file caching should consider using **FsRtlCopyRead** as the file system's entry point for processing fast I/O read requests. This requires that the file system's **DriverEntry** routine set the **FastIoRead** entry point to **FsRtlCopyRead** in the FAST_IO_DISPATCH structure of the file system driver object. In addition, the file system must do the following:

1. For each file on which fast I/O might be performed, the file system must allocate and initialize an FSRTL_COMMON_FCB_HEADER structure.

 In most file systems, this is accomplished by including the FSRTL_COMMON_FCB_HEADER structure in a file control block (FCB) or comparable structure that is used to maintain the state of an open file.

 Storage for the FSRTL_COMMON_FCB_HEADER structure is typically allocated from paged pool.

2. For each file on which fast I/O might be performed, the file system must link any file objects for the file to the FSRTL_COMMON_FCB_HEADER structure. This is done by setting each file object's **FsContext** member to point to this structure (or the FCB or other structure that contains the FSRTL_COMMON_FCB_HEADER structure).

3. When caching a file, the file system must set the **IsFastIoPossible** member of the file's FSRTL_COMMON_FCB_HEADER structure to an appropriate value. This value should be updated as needed for as long as the file remains cached.

 In particular, file systems should set the **IsFastIoPossible** member of the FSRTL_COMMON_FCB_HEADER structure to **FastIoIsQuestionable** as soon as any exclusive byte-range lock on the cached file exists.

If **Wait** is TRUE, **FsRtlCopyRead** is guaranteed to complete the copy request and return TRUE. If the required pages of the cached file are already resident in memory, the data will be copied immediately and no blocking will occur. If any needed pages are not resident, the caller will be put into a wait state until all required pages have been made resident and the data can be copied.

If **Wait** is FALSE, **FsRtlCopyRead** will refuse to block, and will return FALSE, if it cannot acquire the file's main resource or if the required pages of the cached file are not already resident in memory.

The file system's **FastIoCheckIfPossible** routine is responsible for ensuring that the byte range defined by **FileOffset** and **Length** does not include any exclusively locked byte range for which the caller does not pass the appropriate **LockKey** value. If the file system uses the **FsRtl*Xxx*Lock*Yyy*** support routines to manage byte-range locks, this can be accomplished by calling [**FsRtlFastCheckLockForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread) from the **FastIoCheckIfPossible** routine before calling **FsRtlCopyRead**.

To cache a file, use the [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap) routine.

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**FsRtlCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopywrite)

[**FsRtlFastCheckLockForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)