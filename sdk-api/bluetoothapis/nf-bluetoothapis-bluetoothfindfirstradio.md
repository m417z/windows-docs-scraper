# BluetoothFindFirstRadio function

## Description

The **BluetoothFindFirstRadio** function begins the enumeration of local Bluetooth radios.

## Parameters

### `pbtfrp`

Pointer to a [BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params) structure. The **dwSize** member of the **BLUETOOTH_FIND_RADIO_PARAMS** structure pointed to by *pbtfrp* must match the size of the structure.

### `phRadio` [out]

Pointer to where the first enumerated radio handle will be returned. When no longer needed, this handle must be closed via [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## Return value

In addition to the handle indicated by *phRadio*, calling this function will also create a HBLUETOOTH_RADIO_FIND handle for use with the [BluetoothFindNextRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextradio) function. When this handle is no longer needed, it must be closed via the [BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose).

Returns **NULL** upon failure. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information on the error. The following table describe common errors:

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | No Bluetooth radios found. |
| **ERROR_INVALID_PARAMETER** | The *pbtfrp* parameter is **NULL**. |
| **ERROR_REVISION_MISMATCH** | The structure pointed to by *pbtfrp* is not the correct size. |
| **ERROR_OUTOFMEMORY** | Out of memory. |

## See also

[BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params)

[BluetoothFindNextRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextradio)

[BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose)

[BluetoothGetRadioInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetradioinfo)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)