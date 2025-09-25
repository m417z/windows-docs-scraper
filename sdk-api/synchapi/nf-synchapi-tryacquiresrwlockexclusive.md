# TryAcquireSRWLockExclusive function

## Description

Attempts to acquire a slim reader/writer (SRW) lock in exclusive mode. If the call is successful, the calling thread takes ownership of the lock.

## Parameters

### `SRWLock` [in, out]

A pointer to the SRW lock.

## Return value

If the lock is successfully acquired, the return value is nonzero.

if the current thread could not acquire the lock, the return value is zero.

## See also

[AcquireSRWLockExclusive](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-acquiresrwlockexclusive)

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryAcquireSRWLockShared](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryacquiresrwlockshared)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)