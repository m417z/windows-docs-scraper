# BluetoothEnableIncomingConnections function

## Description

The **BluetoothEnableIncomingConnections** function modifies whether a local Bluetooth radio accepts incoming connections.

## Parameters

### `hRadio`

Valid local radio handle for which to change whether incoming connections are enabled, or **NULL**. If **NULL**, the attempt to modify incoming connection acceptance iterates through all local radios; if any radio is modified by the call, the function call succeeds.

### `fEnabled`

Flag specifying whether incoming connection acceptance is to be enabled or disabled. Set to **TRUE** to enable incoming connections, set to **FALSE** to disable incoming connections.

## Return value

Returns **TRUE** if the incoming connection state was successfully changed. If *hRadio* is **NULL**, a return value of **TRUE** indicates that at least one local radio state was successfully changed. Returns **FALSE** if incoming connection state was not changed; if *hRadio* was **NULL**, no radio accepted the state change.

## Remarks

 A radio that is non-connectable is non-discoverable. The radio must be made non-discoverable prior to making a radio non-connectable. Failure to make a radio non-discoverable prior to making it non-connectable will result in failure of the **BluetoothEnableIncomingConnections** function call.

## See also

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)