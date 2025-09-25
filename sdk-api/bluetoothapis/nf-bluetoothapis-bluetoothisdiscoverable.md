# BluetoothIsDiscoverable function

## Description

The **BluetoothIsDiscoverable** function determines whether a Bluetooth radio or radios is discoverable.

## Parameters

### `hRadio`

Valid local radio handle, or **NULL**. If **NULL**, discovery is determined for all local radios; if any radio is discoverable, the function call succeeds.

## Return value

Returns **TRUE** if at least one Bluetooth radio is discoverable. Returns **FALSE** if no Bluetooth radios are discoverable.

## See also

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)