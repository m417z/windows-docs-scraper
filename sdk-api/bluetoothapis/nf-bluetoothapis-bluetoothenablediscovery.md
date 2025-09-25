# BluetoothEnableDiscovery function

## Description

The **BluetoothEnableDiscovery** function changes the discovery state of a local Bluetooth radio or radios.

## Parameters

### `hRadio`

Valid local radio handle, or **NULL**. If **NULL**, discovery is modified on all local radios; if any radio is modified by the call, the function call succeeds.

### `fEnabled`

Flag specifying whether discovery is to be enabled or disabled. Set to **TRUE** to enable discovery, set to **FALSE** to disable discovery.

## Return value

Returns **TRUE** if the discovery state was successfully changed. If *hRadio* is **NULL**, a return value of **TRUE** indicates that at least one local radio state was successfully changed. Returns **FALSE** if discovery state was not changed; if *hRadio* was **NULL**, no radio accepted the state change.

## Remarks

Use the [BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable) function to determine the current state of a Bluetooth radio.
Windows ensures that a discoverable system is connectable, and as such, the radio must allow incoming connections prior to making a radio
discoverable. Failure to allow incoming connections results in the **BluetoothEnableDiscovery** function call failing.

When **BluetoothEnableDiscovery** changes the discovery state, the new state is valid for the lifetime of the calling application. Additionally, if a Bluetooth radio previously made discoverable with this function is disabled and re-enabled via the application, discoverability will not persist. Once the calling application terminates, the discovery state of the specified Bluetooth radio reverts to the state it was in before **BluetoothEnableDiscovery** was called.

## See also

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)