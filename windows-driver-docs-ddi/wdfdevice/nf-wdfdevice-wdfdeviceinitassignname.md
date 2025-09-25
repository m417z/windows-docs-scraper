# WdfDeviceInitAssignName function

## Description

[Applies to KMDF only]

The **WdfDeviceInitAssignName** method assigns a device name to a device's device object.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceName` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that represents the device name.

## Return value

If **WdfDeviceInitAssignName** encounters no errors it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The system cannot allocate space to store the device name. |

## Remarks

If a driver calls **WdfDeviceInitAssignName**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

If a driver calls **WdfDeviceInitAssignName** to assign a name, the driver can subsequently call **WdfDeviceInitAssignName** with a **NULL** *DeviceName* parameter to clear the device name. If the device name is **NULL** and the device object requires a name (because it represents a PDO or a [control device](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects)), the operating system will create a name.

For more information about naming device objects, see [Controlling Device Access in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-device-access-in-kmdf-drivers).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example assigns an [NT device name](https://learn.microsoft.com/windows-hardware/drivers/kernel/nt-device-names) to a device.

```cpp
DECLARE_CONST_UNICODE_STRING(MyDeviceName, L"\\Device\\Ramdisk") ;
status = WdfDeviceInitAssignName(
                                 DeviceInit,
                                 &MyDeviceName
                                 );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WdfDeviceRetrieveDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceretrievedevicename)