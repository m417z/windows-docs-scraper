# WdfWaitLockCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfWaitLockCreate** method creates a framework wait-lock object.

## Parameters

### `LockAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the wait-lock object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Lock` [out]

A pointer to a location that receives a handle to a new framework wait-lock object.

## Return value

**WdfWaitLockCreate** returns STATUS_SUCCESS if the operation succeeds.

For a list of other return values that the **WdfWaitLockCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfWaitLockCreate** method creates a framework wait-lock object. After creating a wait-lock object, a driver can call [WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85)) to acquire the lock and [WdfWaitLockRelease](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfwaitlockrelease) to release the lock.

By default, the new wait-lock object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the wait-lock object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the wait-lock object when it has finished using the object; otherwise, the object will remain until the I/O manager unloads your driver.

For more information about wait locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes), specifies that the wait lock's parent object will be a device object, and calls **WdfWaitLockCreate**.

```cpp
WDF_OBJECT_ATTRIBUTES attributes;
WDFWAITLOCK lockHandle;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = Device;
status = WdfWaitLockCreate(
                           &attributes,
                           &lockHandle
                           );
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85))

[WdfWaitLockRelease](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfwaitlockrelease)