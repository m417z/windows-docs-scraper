## Description

The **WdfSpinLockRelease** method releases a specified spin lock.

## Parameters

### `SpinLock`

A handle to a framework spin-lock object, obtained by a previous call to [WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfSpinLockRelease** method releases the spin lock that a driver obtained by previously calling [**WdfSpinLockAcquire**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockacquire). **WdfSpinLockRelease** also restores the driver's IRQL to the value that it had before the driver called **WdfSpinLockAcquire**.

For more information about spin locks, see [Using Framework Locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks#framework-spin-locks).

## See also

[WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate)

[WdfSpinLockAcquire](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockacquire)

[WdfSpinlock rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlock)

[WdfSpinLockRelease rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlockrelease)