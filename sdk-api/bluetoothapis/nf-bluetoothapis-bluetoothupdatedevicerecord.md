# BluetoothUpdateDeviceRecord function

## Description

The **BluetoothUpdateDeviceRecord** function updates the local computer cache about a Bluetooth device.

## Parameters

### `pbtdi`

A pointer to the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure to update. For more information, see the Remarks section.

## Return value

Returns **ERROR_SUCCESS** upon success. The following table lists common errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pbtdi* parameter is **NULL**. |
| **ERROR_REVISION_MISMATCH** | The **dwSize** member of the structure pointed to in the *pbtdi* parameter is not valid. |

## Remarks

When updating a Bluetooth device record, the requirements for members of the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure, listed in the following table, must be observed.

| Member | Requirement |
| --- | --- |
| **dwSize** | Must match the structure size. |
| **Address** | Must be a previously found radio address. |
| **szName** | Must contain the new name to be stored. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)