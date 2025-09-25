# InitializeSRWLock function

## Description

Initialize a slim reader/writer (SRW) lock.

## Parameters

### `SRWLock` [out]

A pointer to the SRW lock.

## Remarks

An SRW lock must be initialized before it is used. The InitializeSRWLock function is used to initialize a SRW lock dynamically. To initialize the structure statically, assign the constant **SRWLOCK_INIT** to the structure variable.

An SRW lock cannot be moved or copied while in use. The process must not modify the object, and must instead treat it as logically opaque. Only use the SRW functions to manage SRW locks.

An unlocked SRW lock with no waiting threads is in its initial state and can be copied, moved, and forgotten without being explicitly destroyed.

## See also

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)