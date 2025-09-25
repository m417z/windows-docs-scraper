## Description

The **WdfSpinLockAcquire** method acquires a specified spin lock.

## Parameters

### `SpinLock`

A handle to a framework spin-lock object, obtained by a previous call to [WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate).

## Remarks

The **WdfSpinLockAcquire** method returns after the specified spin lock has been acquired. For KMDF, the method returns at IRQL = DISPATCH_LEVEL. For UMDF, the method returns at passive.
Your driver cannot call **WdfSpinLockAcquire** to acquire a spin lock that the driver has specified in a [**WDF_INTERRUPT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.
For more information about spin locks, see [Using Framework Locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks).

## See also

[WdfSpinLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockcreate)

[WdfSpinLockRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockrelease)

[WdfSpinlock rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlock)

[WdfSpinLockRelease rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlockrelease)