## Description

The *DeviceReset* routine is used to reset and recover a malfunctioning device.

## Parameters

### `InterfaceContext` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_reset_interface_standard) structure for the interface.

### `ResetType` [in]

The type of reset being requested. Set this parameter to one of the following [DEVICE_RESET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_reset_type) enumeration values.

- **FunctionLevelDeviceReset**. Specify this value to request a function-level reset, which is restricted to a specific device.

- **PlatformLevelDeviceReset**. Specify this value to request a platform-level reset, which affects a specific device and all other devices that are connected to it via the same power rail or reset line.

For more information about how function-level and platform-level resets are implemented in the device stack, see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard).

### `Flags` [in]

Set to 0. Currently, no flags are defined for this routine.

### `ResetParameters` [in, optional]

If the caller is requesting a function-level device reset, this optional parameter can point to a [FUNCTION_LEVEL_DEVICE_RESET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_function_level_device_reset_parameters) structure that specifies a callback routine that is called when the reset is completed.

## Return value

This routine returns STATUS_SUCCESS if the requested operation succeeds. Otherwise, it returns an appropriate an NTSTATUS error code.

## Remarks

If a function driver detects that the device is not functioning correctly, it should first attempt a function-level reset. If a function-level reset does not fix the issue, then the driver can attempt a more invasive platform-level reset, but a platform-level reset should only be used as the final option.

A function-level reset or platform-level reset must be performed at PASSIVE_LEVEL.

For more information about function-level and platform-level resets, see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard).

## See also

[Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)