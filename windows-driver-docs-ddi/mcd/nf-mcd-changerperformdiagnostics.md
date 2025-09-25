# ChangerPerformDiagnostics function

## Description

**ChangerPerformDiagnostics** performs diagnostic tests on the changer device.

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `changerDeviceError`

Pointer to the buffer of type [**WMI_CHANGER_PROBLEM_DEVICE_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmidata/ns-wmidata-_wmi_changer_problem_device_error) in which the minidriver returns the diagnostic information.

## Return value

**ChangerPerformDiagnostics** returns the status returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INSUFFICIENT_RESOURCES

STATUS_BUFFER_TOO_SMALL

## Remarks

**ChangerPerformDiagnostics** routine performs diagnostic tests on the changer device, and reports the problem to the caller. The kind of tests performed depends on the diagnostics support provided by the device.

## See also

[CHANGER_DEVICE_PROBLEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ne-ntddchgr-_changer_device_problem_type)

[WMI_CHANGER_PROBLEM_DEVICE_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmidata/ns-wmidata-_wmi_changer_problem_device_error)