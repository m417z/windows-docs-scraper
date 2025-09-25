# IoAcquireRemoveLock macro

## Description

The **IoAcquireRemoveLock** routine increments the count for a remove lock, indicating that the associated device object should not be detached from the device stack or deleted.

## Syntax

```cpp
NTSTATUS
IoAcquireRemoveLock (
    _Inout_ PIO_REMOVE_LOCK RemoveLock,
    _In_opt_ PVOID          Tag
    );
```

## Parameters

### `RemoveLock` [in]

Pointer to an **IO_REMOVE_LOCK** structure that the caller initialized with a previous call to [IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock).

### `Tag` [in, optional]

Optionally points to a caller-supplied tag that identifies this instance of acquiring the remove lock. For example, a driver Dispatch routine typically sets this parameter to a pointer to the IRP the routine is processing.

If a driver specifies a *Tag* on a call to **IoAcquireRemoveLock**, the driver must supply the same *Tag* in the corresponding call to [IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock).

The *Tag* does not have to be unique, but should be something meaningful during debugging.

## Remarks

The **IoAcquireRemoveLock** macro wraps and assumes the return value of **IoAcquireRemoveLockEx**, which returns NTSTATUS:

| Return value | Description |
|--|--|
| STATUS_SUCCESS | Indicates the call was successful. |
| STATUS_DELETE_PENDING | Error value indicating the driver has received an IRP_MN_REMOVE_DEVICE for the device and has called **IoReleaseRemoveLockandWait**. That routine is waiting for all remove locks to clear before returning control to the driver. |

If the routine returns any value besides STATUS_SUCCESS, do not start any new operations on the device.

A driver must initialize a remove lock with a call to [IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock) before using the lock.

A driver must call [IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock) to release the lock when it is no longer needed.

For more information, see [Using Remove Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-remove-locks).

## See also

[IoInitializeRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeremovelock)

[IoReleaseRemoveLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelock)

[IoReleaseRemoveLockAndWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelockandwait)