# BluetoothDisplayDeviceProperties function

## Description

The **BluetoothDisplayDeviceProperties** function starts Control Panel device information property sheet.

## Parameters

### `hwndParent`

A handle to the parent window of the property sheet.

### `pbtdi`

A pointer to the [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure that contains information about the Bluetooth device.

## Return value

Returns **TRUE** if the property sheet is successfully displayed. Returns **FALSE** if the property sheet was not displayed successfully; call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for additional error information.

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)

[BluetoothUpdateDeviceRecord](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothupdatedevicerecord)