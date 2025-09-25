# PFN_AUTHENTICATION_CALLBACK_EX callback function

## Description

The *PFN_AUTHENTICATION_CALLBACK_EX* function is a callback function prototype used in conjunction with the [BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthenticationex) function.

**Note** This structure is supported in Windows Vista SP2 and Windows 7.

## Parameters

### `pvParam` [in, optional]

Optional. A context pointer previously passed into the [BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication) function.

### `pAuthCallbackParams` [in]

A [BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_authentication_callback_params) structure that contains device and authentication configuration information specific to the Bluetooth device responding to an authentication request.

## Return value

The return value from this function is ignored by the system.

## See also

[BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthenticationex)

[PFN_AUTHENTICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_authentication_callback)