# WdfFdoInitQueryPropertyEx function

## Description

[Applies to KMDF and UMDF]

The **WdfFdoInitQueryPropertyEx** method retrieves a specified device property.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `DeviceProperty` [in]

A pointer to a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure that identifies the device property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that is pointed to by *PropertyBuffer*.

### `PropertyBuffer` [out]

A caller-supplied pointer to a caller-allocated buffer that receives the requested information. The pointer can be **NULL** if the *BufferLength* parameter is zero.

### `ResultLength` [out]

A caller-supplied location that, on return, contains the
size, in bytes, of the information that the method stored in
*PropertyBuffer*. If the function's return value is
**STATUS_BUFFER_TOO_SMALL**, this location receives the required
buffer size.

### `Type` [out]

A pointer to a **DEVPROPTYPE** variable that, on return, contains the property type value
of the property
data stored in *PropertyBuffer*.

## Return value

If the operation succeeds, **WdfFdoInitQueryPropertyEx** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The supplied buffer is too small to receive the information. |
| **STATUS_INVALID_PARAMETER** | The specified *DeviceProperty* value is invalid. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before receiving device property data, drivers typically call the **WdfFdoInitQueryPropertyEx** method just to obtain the required buffer size. For some properties, the data size can change between when the required size is returned and when the driver calls **WdfFdoInitQueryPropertyEx** again. Therefore, drivers should call **WdfFdoInitQueryPropertyEx** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

It is best to use **WdfFdoInitQueryPropertyEx** only if the required buffer size is known and unchanging, because in that case the driver has to call **WdfFdoInitQueryPropertyEx** only once. If the required buffer size is unknown or varies, the driver should call [WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex).

The driver can call **WdfFdoInitQueryPropertyEx** only before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

After calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), a driver can obtain device property information by calling [WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WdfFdoInitQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitqueryproperty)