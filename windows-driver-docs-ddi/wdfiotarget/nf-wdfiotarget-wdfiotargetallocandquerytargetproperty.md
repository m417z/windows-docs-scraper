# WdfIoTargetAllocAndQueryTargetProperty function

## Description

[Applies to KMDF only]

The **WdfIoTargetAllocAndQueryTargetProperty** method allocates a buffer and retrieves a specified device property for a specified I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate) or from a method that a specialized I/O target supplies.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed value that identifies the device property to be retrieved.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed value that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that the function will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

## Return value

**WdfIoTargetAllocAndQueryTargetProperty** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER or STATUS_INVALID_PARAMETER_2** | The value that the *DeviceProperty* parameter specified was invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The device's drivers have not yet reported the device's properties. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfIoTargetAllocAndQueryTargetProperty** method determines the amount of memory that is necessary to hold the requested device property. This method allocates enough memory to hold the data and returns a handle to a framework memory object that describes the allocated memory. To access the data, your driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

For more information about **WdfIoTargetAllocAndQueryTargetProperty**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example calls **WdfIoTargetAllocAndQueryTargetProperty** to obtain the **DevicePropertyFriendlyName** property. After **WdfIoTargetAllocAndQueryTargetProperty** returns, the driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to obtain a pointer to the buffer that contains the name string.

```cpp
WDFMEMORY  targetName;
NTSTATUS  status;

status = WdfIoTargetAllocAndQueryTargetProperty(
                                                Target,
                                                DevicePropertyFriendlyName,
                                                NonPagedPool,
                                                WDF_NO_OBJECT_ATTRIBUTES,
                                                &targetName
                                                );
```

## See also

[DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetQueryTargetProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetquerytargetproperty)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)