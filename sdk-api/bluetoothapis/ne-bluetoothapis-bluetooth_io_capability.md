# BLUETOOTH_IO_CAPABILITY enumeration

## Description

The **BLUETOOTH_IO_CAPABILITY** enumeration defines the input/output capabilities of a Bluetooth Device.

## Constants

### `BLUETOOTH_IO_CAPABILITY_DISPLAYONLY:0x00`

The Bluetooth device is capable of output via display only.

### `BLUETOOTH_IO_CAPABILITY_DISPLAYYESNO:0x01`

The Bluetooth device is capable of output via a display, and has the additional capability to presenting a yes/no question to the user.

### `BLUETOOTH_IO_CAPABILITY_KEYBOARDONLY:0x02`

The Bluetooth device is capable of input via keyboard.

### `BLUETOOTH_IO_CAPABILITY_NOINPUTNOOUTPUT:0x03`

The Bluetooth device is not capable of input/output.

### `BLUETOOTH_IO_CAPABILITY_UNDEFINED:0xff`

The input/output capabilities for the Bluetooth device are undefined.

## See also

[BLUETOOTH_AUTHENTICATE_RESPONSE](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_authenticate_response)