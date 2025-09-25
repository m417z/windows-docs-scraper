# IoReleaseRemoveLockAndWait macro

## Description

The **IoReleaseRemoveLockAndWait** routine releases a remove lock that the driver acquired in a previous call to [IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock), and waits until all acquisitions of the lock have been released.

## Parameters

### `RemoveLock` [in]

Pointer to an **IO_REMOVE_LOCK** structure that the caller passed in a previous call to **IoAcquireRemoveLock**.

### `Tag` [in]

Pointer to a caller-supplied tag that was passed in a previous call to **IoAcquireRemoveLock**.

If a driver specified a *Tag* when it acquired the lock, the driver must specify the same *Tag* when releasing the lock.

If the call to **IoAcquireRemoveLock** did not specify a *Tag*, then this parameter is **NULL**.

## Remarks

A driver typically calls this routine in its dispatch code for an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request. To allow queued I/O requests to complete, each driver should call **IoReleaseRemoveLockAndWait** *after* it passes the remove IRP to the next-lower driver, and *before* it releases memory, calls [IoDetachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodetachdevice), or calls [IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice). The **IoReleaseRemoveLockAndWait** routine waits for the bus driver to cancel any IRPs that might be outstanding (for example, an [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake) IRP).

A driver must acquire the remove lock before calling **IoReleaseRemoveLockAndWait**. Typically, a driver calls [IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock) early in its [DispatchPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routine, before the switch statement. As a result, the lock is acquired for each PnP operation, including the acquisition that is required before calling **IoReleaseRemoveLockAndWait** in the code that handles **IRP_MN_REMOVE_DEVICE**.

To release a lock from code other than the **IRP_MN_REMOVE_DEVICE** dispatch code, use [IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock).

After **IoReleaseRemoveLockAndWait** has been called for a particular remove lock, subsequent calls to **IoAcquireRemoveLock** for the same remove lock will fail. **IoReleaseRemoveLockAndWait** does not return until all outstanding acquisitions of the remove lock have been released.

After **IoReleaseRemoveLockAndWait** returns, the driver should consider the device to be in a state in which it is ready to be removed and cannot perform I/O operations. Therefore, the driver must not call the [IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock) routine to re-initialize the remove lock. Violation of this rule while the driver is being verified by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) will result in a bug check.

For more information, see [Using Remove Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-remove-locks).

## See also

[DispatchPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch)

[IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake)

[IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock)

[IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice)

[IoDetachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodetachdevice)

[IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock)

[IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock)