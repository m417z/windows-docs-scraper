# BluetoothGetRadioInfo function

## Description

The **BluetoothGetRadioInfo** function obtains information about a Bluetooth radio.

## Parameters

### `hRadio`

A handle to a local Bluetooth radio, obtained by calling the [BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio) or similar functions, or the **SetupDiEnumerateDeviceInterfances** function.

### `pRadioInfo`

A pointer to a [BLUETOOTH_RADIO_INFO](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-bluetooth_radio_info) structure into which information about the radio will be placed. The **dwSize** member of the **BLUETOOTH_RADIO_INFO** structure must match the size of the structure.

## Return value

The following table lists common return values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The radio information was retrieved successfully. |
| **ERROR_INVALID_PARAMETER** | The *hRadio* or *pRadioInfo* parameter is **NULL**. |
| **ERROR_REVISION_MISMATCH** | The **dwSize** member of the [BLUETOOTH_RADIO_INFO](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-bluetooth_radio_info) structure pointed to by *pRadioInfo* is not valid. |

## See also

[BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params)

[BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio)

[BluetoothFindNextRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextradio)

[BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)