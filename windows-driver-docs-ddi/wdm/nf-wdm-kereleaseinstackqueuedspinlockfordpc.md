# KeReleaseInStackQueuedSpinLockForDpc function

## Description

The **KeReleaseInStackQueuedSpinLockForDpc** routine releases a queued spin lock that was acquired by calling [KeAcquireInStackQueuedSpinLockForDpc](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551912(v=vs.85)).

## Parameters

### `LockHandle` [in]

Pointer to the [KLOCK_QUEUE_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that [KeAcquireInStackQueuedSpinLockForDpc](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551912(v=vs.85)) initialized when the queued spin lock was acquired.

## Remarks

For more information about queued spin locks, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks).

If the current IRQL was PASSIVE_LEVEL when the queued spin lock was acquired, **KeReleaseSpinLockForDpc** lowers the current IRQL to PASSIVE_LEVEL. If the current IRQL was DISPATCH_LEVEL when the queued spin lock was acquired, **KeReleaseSpinLockForDpc** does not change the current IRQL.

## See also

[KLOCK_QUEUE_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeAcquireInStackQueuedSpinLockForDpc](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551912(v=vs.85))