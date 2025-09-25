## Description

The **KeInitializeSpinLock** routine initializes a variable of type KSPIN_LOCK.

## Parameters

### `SpinLock` [out]

Pointer to a spin lock, for which the caller must provide the storage.

## Remarks

This routine must be called before an initial call to [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock), to [KeAcquireInStackQueuedSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlock), or to any other support routine that requires a spin lock as an argument.

Storage for a spin lock object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

This function is inlined for x64 systems from Windows XP till Windows 7. Starting in Windows 8, this function is exported from `ntoskrnl.lib`. As a result, if you are using the Windows 10 WDK to build a binary that runs on Windows 7 (and therefore you need NX pool usage to pass Windows 10 HLK tests), you must define `WIN9X_COMPAT_SPINLOCK`. Otherwise, you may see `Windows cannot load the device driver for this hardware. The driver may be corrupted or missing. (Code 39)`.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

Callers of this routine can be running at any IRQL. Usually, a caller is running at IRQL = PASSIVE_LEVEL in an [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

## See also

[KeAcquireInStackQueuedSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlock)

[KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel)

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)

[KeReleaseInStackQueuedSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlock)

[KeReleaseInStackQueuedSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfromdpclevel)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)

[KeReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfromdpclevel)