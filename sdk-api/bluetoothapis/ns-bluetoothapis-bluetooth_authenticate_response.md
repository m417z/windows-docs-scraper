## Description

The **BLUETOOTH_AUTHENTICATE_RESPONSE** structure contains information passed in response to a BTH_REMOTE_AUTHENTICATE_REQUEST event.

## Members

### `bthAddressRemote`

A [BLUETOOTH_ADDRESS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_address_struct) structure that contains the address of the device requesting the authentication response.

**Note** This information can be found in the [PBLUETOOTH_AUTHENTICATION_CALLBACK PARAMS](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-bluetooth_authentication_callback_params) structure retrieved from the callback.

### `authMethod`

A [BLUETOOTH_AUTHENTICATION_METHOD](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_method) enumeration that defines the supported authentication method.

**Note** This information can be found in the [PBLUETOOTH_AUTHENTICATION_CALLBACK PARAMS](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-bluetooth_authentication_callback_params) structure retrieved from the callback.

### `pinInfo`

One of the following structures must be used according to the authentication method defined in *authMethod*. For example, if **BLUETOOTH_AUTHENTICATION_METHOD_LEGACY** is specified, the BLUETOOTH_PIN_INFO structure must be populated.

Contains information for pin authentication.

### `oobInfo`

Contains out-of-band data used to authenticate the device.

### `numericCompInfo`

Contains information for numeric comparison authentication.

### `passkeyInfo`

Contains information for passkey authentication.

### `negativeResponse`

**TRUE** if the authentication request was rejected; otherwise **FALSE**.

## See also

[BLUETOOTH_AUTHENTICATION_METHOD](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_method)