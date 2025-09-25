# WdfFdoInitQueryProperty function

## Description

[Applies to KMDF and UMDF]

The **WdfFdoInitQueryProperty** method retrieves a specified device property.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator value that identifies the device property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that is pointed to by *PropertyBuffer*.

### `PropertyBuffer` [out]

A caller-supplied pointer to a caller-allocated buffer that receives the requested device property. This pointer can be **NULL** if the *BufferLength* parameter is zero.

### `ResultLength` [out]

A caller-supplied location that, on return, contains the size, in bytes, of the information that **WdfFdoInitQueryProperty** stored in *PropertyBuffer*. If this method's return value is STATUS_BUFFER_TOO_SMALL, *ResultLength* receives the required buffer size.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The supplied buffer is too small to receive the information. |
| **STATUS_INVALID_PARAMETER_2** | The specified *DeviceProperty* value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure was not obtained from the driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before receiving device property data, drivers typically must make an initial call to **WdfFdoInitQueryProperty** to obtain the required buffer size. For some properties, the data size can change between the time that the required size is returned and the time that the driver calls this routine again. Therefore, drivers should call **WdfFdoInitQueryProperty** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

It is best to use **WdfFdoInitQueryProperty** only if the required buffer size is known and unchanging, because in that case the driver has to call **WdfFdoInitQueryProperty** only once. If the required buffer size is unknown or varies, the driver should call [WdfFdoInitAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandqueryproperty).

The driver can call **WdfFdoInitQueryProperty** only before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

After calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), a driver can obtain device property information by calling [WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty).

For more information about the **WdfFdoInitQueryProperty** method, see [Creating Device Objects in a Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-function-driver).

Alternatively, you can use [WdfFdoInitQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitquerypropertyex) to access device properties that are exposed through the Unified Property Model.

#### Examples

The following code example obtains a Unicode string that represents the name of a device's enumerator and returns **TRUE** if the string is "PCI".

```cpp
NTSTATUS  status = STATUS_SUCCESS;
WCHAR  enumeratorName[64] = {0};
ULONG  returnSize;
UNICODE_STRING  unicodeEnumName, temp;

status = WdfFdoInitQueryProperty(
                                 DeviceInit,
                                 DevicePropertyEnumeratorName,
                                 sizeof(enumeratorName),
                                 enumeratorName,
                                 &returnSize
                                 );
if(!NT_SUCCESS(status)){
    return status;
}

RtlInitUnicodeString(
                     &unicodeEnumName,
                     enumeratorName
                     );
RtlInitUnicodeString(
                     &temp,
                     L"PCI"
                     );
if(RtlCompareUnicodeString(
                           &unicodeEnumName,
                           &temp,
                           TRUE
                           ) == 0) {
    //
    // This device is a PCI device.
    //
    return TRUE;
}
```

## See also

[WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty)

[WdfFdoInitAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandqueryproperty)