# WdfDeviceQueryPropertyEx function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceQueryPropertyEx** method retrieves a specified device property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceProperty` [in]

A pointer to a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure that identifies the device property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that is pointed to by *PropertyBuffer*.

### `PropertyBuffer` [out]

A caller-supplied pointer to a caller-allocated buffer that receives the requested information. The pointer can be **NULL** if the *BufferLength* parameter is zero.

### `RequiredSize` [out]

A caller-supplied location that, on return, contains the size, in bytes, of the information that the method stored in *PropertyBuffer*. If the function's return value is **STATUS_BUFFER_TOO_SMALL**, this location receives the required buffer size.

### `Type` [out]

A pointer to a **DEVPROPTYPE** variable. If the method is successful, upon return this parameter contains the property type value
of the property
data stored in *PropertyBuffer*.

## Return value

If the operation succeeds, **WdfDeviceQueryPropertyEx** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The supplied buffer is too small to receive the information. |
| **STATUS_INVALID_PARAMETER** | The specified *DeviceProperty* value is invalid. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

You can use **WdfDeviceQueryPropertyEx** to retrieve any property that is exposed through the unified property model, whereas the [WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty) method only allows querying a subset of the unified property model.

Before receiving device property data, drivers typically call the **WdfDeviceQueryPropertyEx** method just to obtain the required buffer size. For some properties, the data size can change between when the required size is returned and when the driver calls **WdfDeviceQueryPropertyEx** again. Therefore, drivers should call **WdfDeviceQueryPropertyEx** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

It is best to use **WdfDeviceQueryPropertyEx** only if the required buffer size is known and unchanging, because in that case the driver has to call **WdfDeviceQueryPropertyEx** only once. If the required buffer size is unknown or varies, the driver should call [WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)

[WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty)