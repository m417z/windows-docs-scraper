# BluetoothAuthenticateMultipleDevices function

## Description

The **BluetoothAuthenticateMultipleDevices** function enables the caller to prompt for multiple devices to be authenticated during a single instance of the Bluetooth Connection wizard.

**Note** **BluetoothAuthenticateMultipleDevices** has been deprecated. Implementation of this API is not recommended.

## Parameters

### `hwndParent`

A window to be the parent of the Authentication wizard. If set to **NULL**, the wizard is parented off the desktop.

### `hRadio`

The valid local radio handle, or **NULL**. If **NULL**, authentication is attempted on all local radios; if any radio succeeds, the function call succeeds.

### `cDevices`

The number of devices in the *pbtdi* array of [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structures.

### `rgbtdi`

An array of [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structures that contain records for the Bluetooth devices to be authenticated.

## Return value

Returns **ERROR_SUCCESS** upon successful completion; check the **fAuthenticate** flag for each device.

The following table lists common errors.

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The user canceled the operation. Check the **fAuthenticate** flag for each Bluetooth device to determine whether any devices were authenticated before the user canceled the operation. |
| **ERROR_INVALID_PARAMETER** | One or more of the devices in the *pbtdi* array was not valid. |
| **ERROR_NO_MORE_ITEMS** | All devices pointed to by *pbtdi* are already marked as authenticated. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)