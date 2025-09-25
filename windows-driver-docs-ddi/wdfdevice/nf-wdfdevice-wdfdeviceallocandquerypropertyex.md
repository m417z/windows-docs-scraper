# WdfDeviceAllocAndQueryPropertyEx function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceAllocAndQueryPropertyEx** method allocates a buffer and retrieves a specified device property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceProperty` [in]

A pointer to a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure that identifies the device property to be retrieved.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed enumerator that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that the function will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

### `Type` [out]

A pointer to a **DEVPROPTYPE** variable. If the method is successful, upon return this parameter contains the property type value
of the property
data stored in *PropertyMemory*.

## Return value

If the operation succeeds, **WdfDeviceAllocAndQueryPropertyEx** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The specified *DeviceProperty* value is invalid. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

You can use **WdfDeviceAllocAndQueryPropertyEx** to retrieve any property that is exposed through the unified property model, whereas the [WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty) method only allows querying a subset of the unified property model.

The **WdfDeviceAllocAndQueryPropertyEx** method determines the amount of memory that is necessary to hold the requested device interface property. It allocates enough memory to hold the data, and returns a handle to a framework memory object that describes the allocated memory. To access the data, your driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)

[WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty)