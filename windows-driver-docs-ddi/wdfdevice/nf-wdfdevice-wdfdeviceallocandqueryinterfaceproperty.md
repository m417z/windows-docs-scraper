# WdfDeviceAllocAndQueryInterfaceProperty function

## Description

[Applies to UMDF only]

The **WdfDeviceAllocAndQueryInterfaceProperty** method allocates a buffer and retrieves a specified device interface property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PropertyData` [in]

A pointer to a [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure that identifies the device interface property to be retrieved.

### `PoolType` [in]

A **POOL_TYPE**-typed enumerator that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that the function will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a **WDFMEMORY**-typed location that receives a handle to a framework memory object.

### `Type` [out]

A pointer to a **DEVPROPTYPE**-typed variable that, on return, identifies the type of property data contained in *PropertyMemory*.

## Return value

If the **WdfDeviceAllocAndQueryInterfaceProperty** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters is incorrect. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfDeviceAllocAndQueryInterfaceProperty** method determines the amount of memory that is necessary to hold the requested device interface property. It allocates enough memory to hold the data, and returns a handle to a framework memory object that describes the allocated memory. To access the data, your driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data)

[WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_interface_property_data_init)

[WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)

[WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)