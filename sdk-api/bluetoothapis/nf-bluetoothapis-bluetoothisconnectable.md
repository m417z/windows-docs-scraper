# BluetoothIsConnectable function

## Description

The **BluetoothIsConnectable** function determines whether a Bluetooth radio or radios is connectable.

## Parameters

### `hRadio`

Valid local radio handle, or **NULL**. If **NULL**, all local radios are checked for connectability; if any radio is connectable, the function call succeeds.

## Return value

Returns **TRUE** if at least one Bluetooth radio is accepting incoming connections. Returns **FALSE** if no radios are accepting incoming connections.

## Remarks

If multiple Bluetooth radios exist, the first radio to return that it is connectable causes the **BluetoothIsConnectable** function to succeed.

## See also

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)