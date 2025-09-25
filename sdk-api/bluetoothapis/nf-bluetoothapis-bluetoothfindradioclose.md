# BluetoothFindRadioClose function

## Description

The **BluetoothFindRadioClose** function closes the enumeration handle associated with finding Bluetooth radios.

## Parameters

### `hFind`

Enumeration handle to close, obtained with a previous call to the [BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio) function.

## Return value

Returns **TRUE** when the handle is successfully closed. Returns **FALSE** if the attempt fails to close the enumeration handle. For additional information on possible errors associated with closing the handle, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params)

[BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio)

[BluetoothFindNextRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextradio)

[BluetoothGetRadioInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetradioinfo)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)