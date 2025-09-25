## Description

The **KefReleaseSpinLockFromDpcLevel** routine releases an executive spin lock without changing the IRQL.

## Parameters

### `SpinLock` [in, out]

Pointer to an executive spin lock for which the caller provides the storage.

## Remarks

Drivers call **KefReleaseSpinLockFromDpcLevel** to release a spin lock acquired by calling **[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)**.

It is an error to call **KefReleaseSpinLockFromDpcLevel** if the specified spin lock was acquired by calling **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)** because the caller's original IRQL is not restored, which can cause deadlocks or fatal page faults.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

- **[KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel)**
- **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)**
- **[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)**
- **[KefAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kefacquirespinlockatdpclevel)**
- **[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)**
- **[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)**
- **[KeReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfromdpclevel)**
- **[KeTryToAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ketrytoacquirespinlockatdpclevel)**
- [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)