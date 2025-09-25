# WdfIoTargetClose function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetClose** method closes a specified remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object that was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver has called **WdfIoTargetClose**, it can call [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) to reopen the remote I/O target.

Drivers that supply an [EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete) callback function must call **WdfIoTargetClose** from within that callback function.

Before the **WdfIoTargetClose** method returns, the framework [cancels](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) all of the target queue's I/O requests.

If a driver has finished using a remote I/O target and will not use the target again, and the target has no child request objects that are still pending, the driver can call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) without first calling **WdfIoTargetClose**. The call to **WdfObjectDelete** will close the remote I/O target, cancel all of the target queue's I/O requests, and delete the I/O target object. (Note that if the remote I/O target's parent object is a device object, the framework closes the target and deletes the target object when it deletes the parent object.) If the target has any child request objects that are still pending, the driver must call **WdfIoTargetClose** before it can safely call **WdfObjectDelete**.

For more information about **WdfIoTargetClose**, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example is an [EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete) callback function that removes a specified I/O target from a driver's collection of I/O targets and then closes the I/O target.

```cpp
VOID
MyEvtIoTargetRemoveComplete(
    WDFIOTARGET IoTarget
)
{
    //
    // Get device information from the I/O target object's
    // context space.
    //
    targetDeviceInfo = GetTargetDeviceInfo(IoTarget);
    deviceExtension = targetDeviceInfo->DeviceExtension;

    //
    // Remove the target device from the collection.
    //
    WdfWaitLockAcquire(
                       deviceExtension->TargetDeviceCollectionLock,
                       NULL
                       );

    WdfCollectionRemove(
                        deviceExtension->TargetDeviceCollection,
                        IoTarget
                        );

    WdfWaitLockRelease(deviceExtension->TargetDeviceCollectionLock);

    //
    // Close the target.
    //
    WdfIoTargetClose(IoTarget);
}
```

## See also

[EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)