## Description

The **KeReleaseInStackQueuedSpinLockFromDpcLevel** routine releases a queued spin lock acquired by [KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel).

## Parameters

### `LockHandle` [in]

Specifies the queued spin lock handle initialized by the call to [KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel) that acquired the lock.

## Remarks

For more information about queued spin locks, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks).

## See also

[KLOCK_QUEUE_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeAcquireInStackQueuedSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel)