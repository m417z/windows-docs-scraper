# BluetoothGetDeviceInfo function

## Description

The **BluetoothGetDeviceInfo** function retrieves information about a remote Bluetooth device. The Bluetooth device must have been previously identified through a successful device inquiry function call.

## Parameters

### `hRadio`

A handle to a local radio, obtained from a call to the [BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio) or similar functions, or from a call to the **SetupDiEnumDeviceInterfaces** function.

### `pbtdi`

A pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure into which data about the first Bluetooth device will be placed. For more information, see Remarks.

## Return value

Returns **ERROR_SUCCESS** upon success, indicating that data about the remote Bluetooth device was retrieved. Returns error codes upon failure. The following table lists common error codes associated with the **BluetoothGetDeviceInfo** function.

| Return code | Description |
| --- | --- |
| **ERROR_REVISION_MISMATCH** | The size of the BLUETOOTH_DEVICE_INFO is not compatible. Check the **dwSize** member of the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure. |
| **ERROR_NOT_FOUND** | The radio is not known by the system, or the **Address** member of the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure is all zeros. |
| **ERROR_INVALID_PARAMETER** | The *pbtdi* parameter is **NULL**. |

## Remarks

The Bluetooth device for which data is obtained must have been previously identified through a successful device inquiry function call.

In the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure pointed to by *pbtdi*, the **dwSize** member must be equivalent to the size, in bytes, of the structure. The **Address** member of the **BLUETOOTH_DEVICE_INFO** structure must contain the Bluetooth address of the remote
device.

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)