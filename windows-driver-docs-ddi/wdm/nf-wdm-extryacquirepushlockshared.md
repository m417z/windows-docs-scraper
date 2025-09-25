## Description

Try to acquire the given push lock for shared access by the calling thread.

## Parameters

### `Lock`

Opaque push lock pointer. This pointer must have been initialized by a previous call to [**ExInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock).

## Return value

If the lock is successfully acquired, the return value is nonzero. If the current thread could not acquire the lock, the return value is zero.

## Remarks

Push locks are similar to ERESOURCE structures (also called resources) in that they can be acquired for shared or exclusive access. For more information about push locks, see the reference entry for [**ExInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock).

Unlike ERESOURCE structures, push locks cannot be acquired recursively. If the caller already has acquired the push lock for exclusive access, the system will hang. If the caller already has acquired the push lock for shared access, it can receive shared access again.

To release the push lock after it is acquired, call [**ExReleasePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockshared). Each call to **ExAcquirePushLockShared** must be matched by a subsequent call to [**ExReleasePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockshared).

When the caller will be given shared access to the given push lock depends on the following:

- If the push lock is currently unowned, shared access is granted immediately to the current thread.

- If the push lock has already been acquired for shared access by another thread and no thread is waiting for exclusive access to the push lock, shared access is granted to the caller immediately. The caller is put into a wait state if there is an exclusive waiter.

- If the push lock has already been acquired for exclusive access by another thread or if there is another thread waiting for exclusive access, the current thread is put into a wait state until the push lock can be acquired.

Before calling this routine, the driver must disable normal kernel APC delivery by calling [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Reenable delivery after the push lock is released by calling [**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

To acquire a push lock for exclusive access, call [**ExAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockexclusive).

## See also

[ExTryAcquirePushLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extryacquirepushlockexclusive)

[ExInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[ExReleasePushLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockexclusive)

[ExAcquirePushLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockshared)

## Syntax

```cpp
BOOLEAN ExTryAcquirePushLockShared(
   Lock
);
```