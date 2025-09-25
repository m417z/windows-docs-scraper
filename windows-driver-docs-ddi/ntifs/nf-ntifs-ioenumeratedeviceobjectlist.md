# IoEnumerateDeviceObjectList function

## Description

The **IoEnumerateDeviceObjectList** routine enumerates a driver's device object list.

## Parameters

### `DriverObject` [in]

A pointer to the driver object for the driver.

### `DeviceObjectList` [out]

A pointer to a caller-allocated array that receives the device object pointers. This array must be allocated from nonpaged pool. This parameter can be NULL. See Remarks.

### `DeviceObjectListSize` [in]

Size, in bytes, of the **DeviceObjectList** array. This parameter can be zero. See Remarks.

### `ActualNumberDeviceObjects` [out]

Actual number of device objects found in the driver object's device object list. Note that if the array at **DeviceObjectList** is too small, the number of device object pointers that are copied into the array will be less than **ActualNumberDeviceObjects**.

## Return value

**IoEnumerateDeviceObjectList** returns an NTSTATUS code such as one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The call to **IoEnumerateDeviceObjectList** completed successfully. |
| STATUS_BUFFER_TOO_SMALL | The array at **DeviceObjectList** is too small to hold the entire device object list. In this case, **IoEnumerateDeviceObjectList** copies as many device object pointers into the array as possible. |

## Remarks

A file system filter driver calls **IoEnumerateDeviceObjectList** to enumerate:

* The device objects it has created. This is commonly done when the driver is preparing to unload. Note that a filter driver cannot safely be unloaded from a running system. For more information, see [**ZwUnloadDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwunloaddriver).

* The device objects created by the base file system, so the filter knows the number of volumes to which it can attach.

**IoEnumerateDeviceObjectList** returns all device objects created by the filter driver. This includes control device objects (CDOs) as well as volume device objects (VDOs). The two types of device objects can be distinguished by the fact that, by convention, CDOs are named and VDOs are not.

In the latter case, the filter driver typically calls **IoEnumerateDeviceObjectList** twice: once to get the number of device objects in the list, and once to get the device object list itself. In the first call, the caller should set the **DeviceObjectList** parameter to NULL and **DeviceObjectListSize** to zero. In the second call, **DeviceObjectList** should contain a pointer to an appropriately-sized pointer array, and **DeviceObjectListSize** should contain the size, in bytes, of that array.

**IoEnumerateDeviceObjectList** increments the reference count on every device object in the list pointed to by **DeviceObjectList**. Thus every successful call to **IoEnumerateDeviceObjectList** must be matched by a subsequent call to [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) for each device object in the list. Failure to do so prevents the system from freeing or deleting these device objects because of an outstanding reference count.

## See also

[**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2)

[**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3)

[**IoGetAttachedDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevice)

[**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference)

[**IoGetLowerDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetlowerdeviceobject)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[**ZwUnloadDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwunloaddriver)