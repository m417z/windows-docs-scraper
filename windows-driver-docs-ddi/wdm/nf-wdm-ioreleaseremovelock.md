# IoReleaseRemoveLock macro

## Description

The **IoReleaseRemoveLock** routine releases a remove lock acquired with a previous call to [IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock).

## Parameters

### `RemoveLock` [in]

Pointer to an **IO_REMOVE_LOCK** structure that the caller passed to a previous call to **IoAcquireRemoveLock**.

### `Tag` [in]

Pointer to a caller-supplied tag that was passed to a previous call to **IoAcquireRemoveLock**.

If a driver specified a *Tag* when it acquired the lock, the driver must specify the same *Tag* when releasing the lock.

If the call to **IoAcquireRemoveLock** did not specify a *Tag*, then this parameter is **NULL**.

## Remarks

A driver calls **IoReleaseRemoveLock** when it has completed the I/O operation for which it called [IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock).

* For I/O operations (including power and PnP IRPs) that set an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, a driver should call **IoReleaseRemoveLock** in the *IoCompletion* routine, after calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest).
* For I/O operations that do not set an *IoCompletion* routine, a driver should call **IoReleaseRemoveLock** after passing the current IRP to the next-lower driver, but before exiting the dispatch routine.

Each call to [IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock) must have a corresponding call to **IoReleaseRemoveLock**.

**IoReleaseRemoveLock** decrements the count of outstanding acquisitions of the remove lock. If the count goes to zero and the driver has received an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request, **IoReleaseRemoveLock** sets an internal event. When a driver is ready to delete a device object, it calls a similar routine, [IoReleaseRemoveLockAndWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelockandwait). The driver makes this call only in its dispatch code for an **IRP_MN_REMOVE_DEVICE** request. The **IoReleaseRemoveLockAndWait** routine does not return until **IoReleaseRemoveLock** sets the event that indicates the acquisition count is zero. After **IoReleaseRemoveLockAndWait** returns, the driver can safely detach and delete the device object.

For more information, see [Using Remove Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-remove-locks).

## See also

[IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock)

[IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock)

[IoReleaseRemoveLockAndWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelockandwait)