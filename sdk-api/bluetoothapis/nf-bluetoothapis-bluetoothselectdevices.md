# BluetoothSelectDevices function

## Description

The
**BluetoothSelectDevices** function enables Bluetooth device selection.

## Parameters

### `pbtsdp`

A pointer to a
[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params) structure that identifies Bluetooth devices.

## Return value

Returns **TRUE** if a user selected a device.

Returns **FALSE** if no valid data was returned. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to retrieve error information. The following conditions apply to returned error information.

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The user canceled the request. |
| **ERROR_INVALID_PARAMETER** | The *pbtsdp* parameter is **NULL**. |
| **ERROR_REVISION_MISMATCH** | The structure passed in *pbtsdp* is of unknown size. |

## Remarks

The **BluetoothSelectDevices** function opens a common dialog box for selecting Bluetooth devices. The list of devices displayed to the user is determined by the flags and settings the caller specifies in the *pbtsdp* parameter.

If
**BluetoothSelectDevices** returns **TRUE**, the **pDevices** member of the
[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params) structure points to valid data. The caller should verify that the **fAuthenticated** and **fRemembered** flags in the
**BLUETOOTH_SELECT_DEVICE_PARAMS** structure to determine which devices were successfully authenticated, and which devices are valid selections for the user. Call the
**BluetoothSelectDevicesFree** function to free resources only if the
**BluetoothSelectDevices** function returns **TRUE**.

## See also

[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params)

[PFN_DEVICE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_device_callback)