# BluetoothFindFirstDevice function

## Description

The **BluetoothFindFirstDevice** function begins the enumeration Bluetooth devices.

## Parameters

### `pbtsp`

Pointer to a [BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params) structure. The **dwSize** member of the **BLUETOOTH_DEVICE_SEARCH_PARAMS** structure pointed to by *pbtsp* must match the size of the structure.

### `pbtdi`

Pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure into which information about the first Bluetooth device found is placed. The **dwSize** member of the **BLUETOOTH_DEVICE_INFO** structure pointed to by *pbtdi* must match the size of the structure, or the call to the **BluetoothFindFirstDevice** function fails.

## Return value

Returns a valid handle to the first Bluetooth device upon successful completion, and the *pbtdi* parameter points to information about the device. When this handle is no longer needed, it must be closed via the [BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose).

Returns **NULL** upon failure. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information on the error. The following table describe common errors:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pbtsp* or *pbtdi* parameter is **NULL**. |
| **ERROR_REVISION_MISMATCH** | The structure pointed to by *pbtsp* or *pbtdi* is not the correct size. |

## Remarks

The BluetoothFindFirstDevice function does not find Bluetooth Low Energy (LE) devices.
To access Bluetooth LE devices, use the
[Windows Runtime Bluetooth Low Energy APIs](https://learn.microsoft.com/windows/uwp/devices-sensors/bluetooth-low-energy-overview).
The Windows Runtime APIs for Bluetooth work in both UWP and classic desktop apps.

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)

[BluetoothUpdateDeviceRecord](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothupdatedevicerecord)