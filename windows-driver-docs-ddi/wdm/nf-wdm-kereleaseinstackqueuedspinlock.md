# KeReleaseInStackQueuedSpinLock function

## Description

The **KeReleaseInStackQueuedSpinLock** routine releases a queued spin lock acquired by [KeAcquireInStackQueuedSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551899(v=vs.85)).

## Parameters

### `LockHandle` [in]

Specifies the queued spin lock handle initialized by the call to [KeAcquireInStackQueuedSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551899(v=vs.85)) that acquired the lock.

## Remarks

This routine restores the original IRQL that the operating system saved at the beginning of the **KeAcquireInStackQueuedSpinLock** call.

For more information about queued spin locks, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks).

Use Hal.lib on 32-bit versions of Windows and Ntoskrnl.lib on 64-bit versions of Windows.

## See also

[KLOCK_QUEUE_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeAcquireInStackQueuedSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551899(v=vs.85))