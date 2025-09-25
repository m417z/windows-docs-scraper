# WdfDeviceAllocAndQueryProperty function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceAllocAndQueryProperty** method allocates a buffer and retrieves a specified device property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator that identifies the device property to be retrieved.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed enumerator that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that the function will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

## Return value

If the operation succeeds, **WdfDeviceAllocAndQueryProperty** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER or STATUS_INVALID_PARAMETER_2** | The specified *DeviceProperty* value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The device's drivers have not yet reported the device's properties. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDeviceAllocAndQueryProperty** method determines the amount of memory that is necessary to hold the requested device property. It allocates enough memory to hold the data, and returns a handle to a framework memory object that describes the allocated memory. To access the data, your driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

Alternatively, you can use [WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex) to access device properties that are exposed through the Unified Property Model.

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure with attributes for the framework memory object that the framework will create for the requested property. Then, the example calls **WdfDeviceAllocAndQueryProperty** to obtain the **DevicePropertyPhysicalDeviceObjectName** property. After **WdfDeviceAllocAndQueryProperty** returns, the driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to obtain a pointer to the buffer that contains the name string.

```cpp
WDF_OBJECT_ATTRIBUTES  attributes;
NTSTATUS  status;
WDFDEVICE  device;
WDFMEMORY  memory;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = device;

status = WdfDeviceAllocAndQueryProperty(device,
                                        DevicePropertyPhysicalDeviceObjectName,
                                        NonPagedPool,
                                        &attributes,
                                        &memory
                                        );
if (!NT_SUCCESS(status)) {
    return STATUS_UNSUCCESSFUL;
}
```

## See also

[WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty)