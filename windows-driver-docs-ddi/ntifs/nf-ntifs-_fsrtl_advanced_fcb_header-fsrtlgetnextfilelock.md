# FsRtlGetNextFileLock function

## Description

The **FsRtlGetNextFileLock** routine is used to enumerate the byte-range locks that currently exist for a specified file.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to **FsRtlAllocateFileLock** or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `Restart` [in]

Set to **TRUE** if the enumeration is to start at the beginning of the list of byte range locks. Set to **FALSE** if resuming the enumeration from a previous call.

To enumerate all byte-range locks for a given file, use **FsRtlGetNextFileLock** as follows:

```
for (p = FsRtlGetNextFileLock( FileLock, TRUE );
     p != NULL;
     p = FsRtlGetNextFileLock( FileLock, FALSE )) {
        // Process the lock information pointed to by p
}
```

## Return value

**FsRtlGetNextFileLock** returns a pointer to the FILE_LOCK_INFO structure for the next byte-range lock, if one exists. If there are no more byte-range locks for this file, **FsRtlGetNextFileLock** returns **NULL**.

## Remarks

The byte range locks are not enumerated in any particular order.

Note that because the current enumeration state is stored in the FILE_LOCK structure, callers must be careful to synchronize calls to **FsRtlGetNextFileLock**, and to avoid modifying any of the structures that it returns. If multiple threads attempt to use **FsRtlGetNextFileLock** at the same time, the results will be unpredictable, and the enumeration will not be reliably complete.

## See also

[FsRtlAreThereCurrentFileLocks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlaretherecurrentfilelocks)

[FsRtlCheckLockForReadAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[FsRtlCheckLockForWriteAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforwriteaccess)

[FsRtlFastCheckLockForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)

[FsRtlFastCheckLockForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite)

[FsRtlFastLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfastlock)

[FsRtlFastUnlockAll](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockall)

[FsRtlFastUnlockAllByKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockallbykey)

[FsRtlFastUnlockSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlocksingle)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[FsRtlProcessFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[FsRtlUninitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)