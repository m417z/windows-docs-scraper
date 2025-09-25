## Description

The **KefAcquireSpinLockAtDpcLevel** routine acquires a spin lock when the caller is already running at IRQL >= DISPATCH_LEVEL.

## Parameters

### `SpinLock`

Pointer to an initialized KSPIN_LOCK spin lock for which the caller must provide the storage. The spin lock must be from non-paged pool.

## Remarks

Drivers call **KefAcquireSpinLockAtDpcLevel** instead of **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)** for better driver performance if and only if they are already running at an IRQL of DISPATCH_LEVEL or above.

If a driver is running at IRQL <= APC_LEVEL, it should call KeAcquireSpinLock to have IRQL raised by that routine. **KefAcquireSpinLockAtDpcLevel** assumes the caller is already running at IRQL >= DISPATCH_LEVEL, so no raise is necessary.

The caller should release the spin lock with **[KefReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kefreleasespinlockfromdpclevel)** as quickly as possible.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

## See also

- **[KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel)**
- **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)**
- **[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)**
- **[KefReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kefreleasespinlockfromdpclevel)**
- **[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)**
- **[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)**
- **[KeReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfromdpclevel)**
- **[KeTryToAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ketrytoacquirespinlockatdpclevel)**
- [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)