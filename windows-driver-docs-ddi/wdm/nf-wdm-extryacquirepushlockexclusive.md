## Description

Try to acquire the given push lock for exclusive access by the calling thread.

## Parameters

### `Lock`

Opaque push lock pointer. This pointer must have been initialized by a previous call to [**ExInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock).

## Return value

If the lock is successfully acquired, the return value is nonzero. If the current thread could not acquire the lock, the return value is zero.

## Remarks

Push locks are similar to ERESOURCE structures (also called resources) in that they can be acquired for shared or exclusive access. For more information about push locks, see the reference entry for [**ExInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock).

Unlike ERESOURCE structures, push locks cannot be acquired recursively. If the caller already has acquired the push lock for exclusive or shared access, the thread hangs.
When the caller is given exclusive access to the given push lock, depends on the following:

- If the push lock is currently unowned, exclusive access is granted immediately to the current thread.

- If the push lock has already been acquired for exclusive or shared access by another thread, the current thread is put into a wait state until the push lock can be acquired.

Before calling this routine, the driver must disable normal kernel APC delivery by calling [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Reenable delivery after the push lock is released by calling [**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

To release the push lock after it is acquired, call [**ExReleasePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockexclusive). Every call to ExAcquirePushLockExclusive must be matched by a subsequent call to [**ExReleasePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockexclusive).

To acquire a push lock for shared access, call [**ExAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockshared).

## See also

[ExTryAcquirePushLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extryacquirepushlockshared)

[ExInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[ExReleasePushLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasepushlockexclusive)

[ExAcquirePushLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockshared)

## Syntax

```cpp
BOOLEAN ExTryAcquirePushLockExclusive(
   Lock
);
```