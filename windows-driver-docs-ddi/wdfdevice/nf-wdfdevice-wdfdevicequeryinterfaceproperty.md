# WdfDeviceQueryInterfaceProperty function

## Description

[Applies to UMDF only]

The **WdfDeviceQueryInterfaceProperty** method retrieves a specified device interface property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PropertyData` [in]

A pointer to a [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure that identifies the device interface property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that is pointed to by *PropertyBuffer.*

### `PropertyBuffer` [out]

A pointer to a caller-allocated buffer that receives the requested device interface property. The pointer can be NULL if the *BufferLength* parameter is zero.

### `ResultLength` [out]

A caller-supplied location that, on return, contains the size, in bytes, of the information that **WdfDeviceQueryInterfaceProperty** stored in *PropertyBuffer*. If the function's return value is **STATUS_BUFFER_TOO_SMALL**, this location receives the required buffer size.

### `Type` [out]

A pointer to a **DEVPROPTYPE**-typed variable that identifies the type of property data that **WdfDeviceQueryInterfaceProperty** stored in the buffer that *PropertyBuffer* points to.

## Return value

If the **WdfDeviceQueryInterfaceProperty** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The input buffer is too small to receive the information. |
| **STATUS_INVALID_PARAMETER_2** | The specified parameter value is invalid. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before receiving device property data, drivers typically call the **WdfDeviceQueryInterfaceProperty** method just to obtain the required buffer size. For some properties, the data size can change between when the required size is returned and when the driver calls **WdfDeviceQueryInterfaceProperty** again. Therefore, drivers should call **WdfDeviceQueryInterfaceProperty** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

It is best to use **WdfDeviceQueryInterfaceProperty** only if the required buffer size is known and unchanging, because in that case the driver has to call **WdfDeviceQueryInterfaceProperty** only once. If the required buffer size is unknown or varies, the driver should call [WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data)

[WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_interface_property_data_init)

[WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)

[WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)