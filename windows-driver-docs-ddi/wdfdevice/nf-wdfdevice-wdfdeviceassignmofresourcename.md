# WdfDeviceAssignMofResourceName function

## Description

[Applies to KMDF only]

The **WdfDeviceAssignMofResourceName** method registers a MOF resource name for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `MofResourceName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that specifies the name of a MOF resource.

## Return value

If the operation succeeds, **WdfDeviceAssignMofResourceName** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver has already called [WdfDeviceAssignMofResourceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignmofresourcename). |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory is available. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver that provides a MOF file to support WMI must call **WdfDeviceAssignMofResourceName**, typically from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. The MOF resource name is the file name that the driver specifies in a **MofResource** statement in its resource script (RC) file. For more information about specifying a MOF resource name, see [Compiling a Driver's MOF File](https://learn.microsoft.com/windows-hardware/drivers/kernel/compiling-a-driver-s-mof-file).

A driver that [enumerates the devices on a bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus) can call **WdfDeviceAssignMofResourceName** for the parent device, and the framework will use the parent's MOF resource name for child devices.

For more information about WMI, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

#### Examples

The following code example declares a Unicode string that represents a MOF resource name and then registers the name.

```cpp
NTSTATUS  status;
DECLARE_CONST_UNICODE_STRING(mofRsrcName, MOFRESOURCENAME);

status = WdfDeviceAssignMofResourceName(
                                        Device,
                                        &mofRsrcName
                                        );
if (!NT_SUCCESS(status)) {
    return status;
}
```