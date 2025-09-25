# WdfDeviceRetrieveDeviceInterfaceString function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceRetrieveDeviceInterfaceString** method retrieves the symbolic link name that the operating system assigned to a device interface that the driver registered for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `InterfaceClassGUID` [in]

A pointer to a GUID that identifies the device interface class.

### `ReferenceString` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that describes a reference string for the device interface. This parameter is optional and can be **NULL** if the driver did not specify a reference string when it called [WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface).

### `String` [in]

A handle to a [framework string object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects). The framework will assign the symbolic link name's Unicode string to the string object.

## Return value

**WdfDeviceRetrieveDeviceInterfaceString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfDeviceRetrieveDeviceInterfaceString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceretrievedeviceinterfacestring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INVALID_DEVICE_REQUEST** | The specified device object was initialized by [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate). |
| **STATUS_OBJECT_NAME_NOT_FOUND** | A device interface that matches the specified GUID and reference string could not be found. |
| **STATUS_INVALID_DEVICE_STATE** | The driver called [WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface) but the system has not yet assigned a symbolic link name to the device interface. |

**WdfDeviceRetrieveDeviceInterfaceString** might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about device interfaces, see [Using Device Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces).

#### Examples

The following code example creates a string object and then retrieves a specified device interface's symbolic link name.

```cpp
NTSTATUS status;
WDFSTRING string;

status = WdfStringCreate(
                         NULL,
                         WDF_NO_OBJECT_ATTRIBUTES,
                         &string
                         );
if (NT_SUCCESS(status)) {
    status = WdfDeviceRetrieveDeviceInterfaceString(
                         Device,
                         &GUID_DEVINTERFACE_DDI_TEST1,
                         NULL,
                         string
                         );
    if (!NT_SUCCESS(status)) {
        return status;
    }
}
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate)

[WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)