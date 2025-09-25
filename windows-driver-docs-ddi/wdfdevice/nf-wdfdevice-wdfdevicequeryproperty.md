# WdfDeviceQueryProperty function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceQueryProperty** method retrieves a specified device property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator that identifies the device property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that is pointed to by *PropertyBuffer*.

### `PropertyBuffer` [out]

A caller-supplied pointer to a caller-allocated buffer that receives the requested information. The pointer can be **NULL** if the *BufferLength* parameter is zero.

### `ResultLength` [out]

A caller-supplied location that, on return, contains the size, in bytes, of the information that the method stored in *PropertyBuffer*. If the function's return value is STATUS_BUFFER_TOO_SMALL, this location receives the required buffer size.

## Return value

If the operation succeeds, **WdfDeviceQueryProperty** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The supplied buffer is too small to receive the information. |
| **STATUS_INVALID_PARAMETER_2** | The specified *DeviceProperty* value is invalid |
| **STATUS_INVALID_DEVICE_REQUEST** | The device's drivers have not yet reported the device's properties. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before receiving device property data, drivers typically call the **WdfDeviceQueryProperty** method just to obtain the required buffer size. For some properties, the data size can change between when the required size is returned and when the driver calls **WdfDeviceQueryProperty** again. Therefore, drivers should call **WdfDeviceQueryProperty** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

It is best to use **WdfDeviceQueryProperty** only if the required buffer size is known and unchanging, because in that case the driver has to call **WdfDeviceQueryProperty** only once. If the required buffer size is unknown or varies, the driver should call [WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty).

Alternatively, you can use [WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex) to access device properties that are exposed through the Unified Property Model.

#### Examples

The following code example obtains a device's **DevicePropertyBusTypeGuid** property. The example calls **WdfDeviceQueryProperty** instead of [WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty) because the length of a GUID is known.

```cpp
GUID  busTypeGuid;
ULONG  resultLength = 0;
NTSTATUS  status;

status = WdfDeviceQueryProperty(
                                device,
                                DevicePropertyBusTypeGuid,
                                sizeof(GUID),
                                (PVOID)&busTypeGuid,
                                &resultLength
                                );
```

## See also

[WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty)

[WdfFdoInitQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitqueryproperty)