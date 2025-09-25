# BluetoothSendAuthenticationResponse function

## Description

The **BluetoothSendAuthenticationResponse** function is called when an authentication request
to send the passkey response is received.

**Note** When developing for Windows Vista SP2 and Windows 7 the use of [BluetoothSendAuthenticationResponseEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponseex) is recommended.

## Parameters

### `hRadio`

Optional handle to the local radio handle, or **NULL**. If **NULL**, the function attempts to send an authentication response on all local radios.

### `pbtdi`

Pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure describing the Bluetooth device being authenticated. This can be the same structure passed to the callback function.

### `pszPasskey`

Pointer to a UNICODE zero-terminated string of the passkey response
to be sent back to the authenticating device. the *pszPasskey* parameter can be no larger than BLUETOOTH_MAX_PASSKEY_SIZE, excluding **NULL**. If translation to ANSI is performed, the *pszPasskey* parameter cannot be larger than 16 bytes, excluding **NULL**.

## Return value

 Returns ERROR_SUCCESS when the device accepts the passkey response; the device is authenticated. Any other return value indicates failure. The following table describes common errors:

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The Bluetooth device denied the passkey response. This error is also returned if a communication problem exists with the local radio. |
| **E_FAIL** | The device returned a failure code during authentication. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponseEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponseex)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)