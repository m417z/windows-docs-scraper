# ReleaseSRWLockShared function

## Description

Releases a slim reader/writer (SRW) lock that was acquired in shared mode.

## Parameters

### `SRWLock` [in, out]

A pointer to the SRW lock.

## Remarks

The SRW lock must be released by the same thread that acquired it. You can use [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) to help verify that your program uses SRW locks correctly (enable Locks checker from Basic group).

## See also

[AcquireSRWLockShared](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-acquiresrwlockshared)

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)