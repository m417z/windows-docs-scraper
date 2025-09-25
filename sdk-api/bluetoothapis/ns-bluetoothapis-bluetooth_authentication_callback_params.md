# BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS structure

## Description

The **BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS** structure contains specific configuration information about the Bluetooth device responding to an authentication request.

## Members

### `deviceInfo`

A [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure that contains information about a Bluetooth device.

### `authenticationMethod`

A [BLUETOOTH_AUTHENTICATION_METHOD](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_method) enumeration that defines the authentication method utilized by the Bluetooth device.

### `ioCapability`

A [BLUETOOTH_IO_CAPABILITY](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_io_capability) enumeration that defines the input/output capabilities of the Bluetooth device.

### `authenticationRequirements`

A [BLUETOOTH_AUTHENTICATION_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_requirements) specifies the 'Man in the Middle' protection required for authentication.

### `Numeric_Value`

A **ULONG** value used for Numeric Comparison authentication.

### `Passkey`

A **ULONG** value used as the passkey used for authentication.

## See also

[BLUETOOTH_AUTHENTICATION_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_requirements)

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_IO_CAPABILITY](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_io_capability)