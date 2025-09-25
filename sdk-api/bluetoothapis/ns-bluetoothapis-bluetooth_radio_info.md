# BLUETOOTH_RADIO_INFO structure

## Description

The **BLUETOOTH_RADIO_INFO** structure contains information about a Bluetooth radio.

## Members

### `dwSize`

Size, in bytes, of the structure.

### `address`

Address of the local Bluetooth radio.

### `szName`

Name of the local Bluetooth radio.

### `ulClassofDevice`

Device class for the local Bluetooth radio.

### `lmpSubversion`

This member contains data specific to individual Bluetooth device manufacturers.

### `manufacturer`

Manufacturer of the Bluetooth radio, expressed as a **BTH_MFG_Xxx** value. For more information about the Bluetooth assigned numbers document and a current list of values, see the Bluetooth specification at [www.bluetooth.com](https://www.bluetooth.com/).

## See also

[BLUETOOTH_FIND_RADIO_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_find_radio_params)

[BluetoothFindFirstRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio)

[BluetoothFindNextRadio](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextradio)

[BluetoothFindRadioClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindradioclose)

[BluetoothGetRadioInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetradioinfo)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)