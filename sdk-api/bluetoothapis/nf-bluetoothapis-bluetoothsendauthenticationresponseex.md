# BluetoothSendAuthenticationResponseEx function

## Description

The **BluetoothSendAuthenticationResponseEx** function is called when an authentication request
to send the passkey or a Numeric Comparison response is made.

**Note** This API is supported in Windows Vista SP2 and Windows 7.

## Parameters

### `hRadioIn` [in, optional]

A handle of the Bluetooth radio device to specify local service information for.

### `pauthResponse` [in]

Pointer to a [BLUETOOTH_AUTHENTICATE_RESPONSE](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_authenticate_response) structure containing the response to the **BTH_REMOTE_AUTHENTICATE_REQUEST** event.

## Return value

Returns ERROR_SUCCESS upon successful completion; returns the following error codes upon failure:

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The device was denied the passkey response. This may also indicate a communications problem with the local radio device. |
| **E_FAIL** | The device returned a failure code during authentication. |

## Remarks

Callers can only use this function to respond to a pending authentication request. Applications should register with [BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication) in order to be notified of incoming authentication requests.

Only the **BLUETOOTH_AUTHENTICATION_METHOD_LEGACY**, **BLUETOOTH_AUTHENTICATION_METHOD_NUMERIC_COMPARISON** and **BLUETOOTH_AUTHENTICATION_METHOD_PASSKEY_NOTIFICATION** response types are valid.

## See also

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)