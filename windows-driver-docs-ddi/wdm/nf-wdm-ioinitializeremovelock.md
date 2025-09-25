# IoInitializeRemoveLock macro

## Description

The **IoInitializeRemoveLock** routine initializes a remove lock for a device object.

## Parameters

### `Lock` [in]

Pointer to a caller-supplied **IO_REMOVE_LOCK** structure that this routine initializes with information about the lock, including a counter and a synchronization event. A driver writer must allocate this structure as part of the device object's device extension.

### `Tag` [in]

Specifies a tag to identify the creator of the lock. Driver writers typically use a 4-character string, specified in reverse order, like the tags used for [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

The I/O system uses this parameter if [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) is enabled. The caller should always supply a nonzero tag value for this parameter.

### `Maxmin` [in]

Specifies the maximum number of minutes that this lock should be held. A value of zero means there is no limit. This value is typically used during debugging to identify a driver routine that holds the lock longer than expected.

The I/O system uses this parameter if Driver Verifier is enabled.

### `HighWater` [in]

Specifies the maximum number of outstanding acquisitions allowed on the lock. Use 0 to specify no maximum. *HighWatermark* must be <= 0x7FFFFFFF.

The I/O system uses this parameter if Driver Verifier is enabled.

## Remarks

A driver can use a remove lock to track outstanding I/O operations on a device and to determine when the driver can delete its device object in response to an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request.

Before calling **IoInitializeRemoveLock**, a driver should allocate an **IO_REMOVE_LOCK** structure in its [device extension](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions). A driver typically calls **IoInitializeRemoveLock** in its [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine, when the driver initializes the rest of the device extension for a device object.

After the **IoReleaseRemoveLockAndWait** routine returns, the driver should consider the device to be in a state in which it is ready to be removed and cannot perform I/O operations. Therefore, the driver must not call **IoInitializeRemoveLock** to re-initialize the remove lock. Violation of this rule while the driver is being verified by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) will result in a bug check.

Because the driver stores the **IO_REMOVE_LOCK** structure in the device extension of a device object, the remove lock is deleted when the driver deletes the device extension as part of processing an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request.

For more information, see [Using Remove Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-remove-locks).

## See also

[IoAcquireRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquireremovelock)

[IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock)

[IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock)

[IoReleaseRemoveLockAndWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelockandwait)