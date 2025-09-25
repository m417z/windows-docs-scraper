# BluetoothFindNextDevice function

## Description

The **BluetoothFindNextDevice** function finds the next Bluetooth device.

## Parameters

### `hFind`

Handle for the query obtained in a previous call to the [BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice) function.

### `pbtdi`

Pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure into which information about the next Bluetooth device found is placed. The **dwSize** member of the **BLUETOOTH_DEVICE_INFO** structure pointed to by *pbtdi* must match the size of the structure, or the call to **BluetoothFindNextDevice** fails.

## Return value

Returns **TRUE** when the next device is successfully found, and the *pbtdi* parameter points to information about the device. Returns **FALSE** upon error. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information on the error. The following table describe common errors:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is **NULL**. |
| **ERROR_NO_MORE_ITEMS** | No more devices were found. |
| **ERROR_OUTOFMEMORY** | Out of memory. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)

[BluetoothUpdateDeviceRecord](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothupdatedevicerecord)