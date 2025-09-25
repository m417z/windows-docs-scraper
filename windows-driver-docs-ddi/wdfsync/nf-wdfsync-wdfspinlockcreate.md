# WdfSpinLockCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfSpinLockCreate** method creates a framework spin-lock object.

## Parameters

### `SpinLockAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the spin-lock object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `SpinLock` [out]

A pointer to a location that receives a handle to a new framework spin-lock object.

## Return value

**WdfSpinLockCreate** returns STATUS_SUCCESS if the operation succeeds.

For a list of other return values that the **WdfSpinLockCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfSpinLockCreate** method creates a framework spin-lock object. After creating a spin-lock object, a driver can call [WdfSpinLockAcquire](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550040(v=vs.85)) to acquire the lock and [WdfSpinLockRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550044(v=vs.85)) to release the lock.

By default, the new spin-lock object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the spin-lock object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the spin-lock object when it has finished using the object; otherwise, the object will remain until the I/O manager unloads your driver.

For more information about spin locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes), specifies that the spin lock's parent object will be a device object, and calls **WdfSpinLockCreate**.

```cpp
WDF_OBJECT_ATTRIBUTES attributes;
WDFSPINLOCK lockHandle;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = Device;
status = WdfSpinLockCreate(
                           &attributes,
                           &lockHandle
                           );
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfSpinLockAcquire](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockacquire)

[WdfSpinLockRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfspinlockrelease)

[WdfSpinlock rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlock)

[WdfSpinLockRelease rule (KMDF)](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfspinlockrelease)