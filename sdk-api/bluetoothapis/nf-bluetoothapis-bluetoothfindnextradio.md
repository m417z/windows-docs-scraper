# BluetoothFindNextRadio function

## Description

The **BluetoothFindNextRadio** function finds the next Bluetooth radio.

## Parameters

### `hFind` [in]

Handle returned by a previous call to the [BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio) function. Use [BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose) to close this handle when it is no longer needed.

### `phRadio` [out]

Pointer to where the next enumerated radio handle will be returned. When no longer needed, this handle must be released via [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## Return value

Returns **TRUE** when the next available radio is found.

Returns **FALSE** when no new radios are found. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information on the error. The following table describe common errors:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is **NULL**. |
| **ERROR_NO_MORE_ITEMS** | No more radios were found. |
| **ERROR_OUTOFMEMORY** | Out of memory. |

## See also

[BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params)

[BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio)

[BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose)

[BluetoothGetRadioInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetradioinfo)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)