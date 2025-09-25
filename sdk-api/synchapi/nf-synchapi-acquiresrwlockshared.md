# AcquireSRWLockShared function

## Description

Acquires a slim reader/writer (SRW) lock in shared mode.

## Parameters

### `SRWLock` [in, out]

A pointer to the SRW lock.

## -Remarks

Successful acquisition of an SRW lock in shared mode typically permits other threads to acquire the same lock in shared mode, but doesn't guarantee that such acquisitions always succeed. An SRW lock may limit its simultaneous shared mode acquisitions for performance reasons.

## See also

[ReleaseSRWLockShared](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-releasesrwlockshared)

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)