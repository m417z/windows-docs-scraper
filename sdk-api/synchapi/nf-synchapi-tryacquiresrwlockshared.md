# TryAcquireSRWLockShared function

## Description

Attempts to acquire a slim reader/writer (SRW) lock in shared mode. If the call is successful, the calling thread takes ownership of the lock.

## Parameters

### `SRWLock` [in, out]

A pointer to the SRW lock.

## Return value

If the lock is successfully acquired, the return value is nonzero.

if the current thread could not acquire the lock, the return value is zero.

## -Remarks

Successful acquisition of an SRW lock in shared mode typically permits other threads to acquire the same lock in shared mode, but doesn't guarantee that such acquisitions always succeed. An SRW lock may limit its simultaneous shared mode acquisitions for performance reasons.

## See also

[AcquireSRWLockShared](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-acquiresrwlockshared)

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryAcquireSRWLockExclusive](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryacquiresrwlockexclusive)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)