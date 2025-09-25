# BluetoothRegisterForAuthentication function

## Description

The **BluetoothRegisterForAuthentication** function registers a callback function that is called when a particular Bluetooth device requests authentication.

**Note** When developing for Windows Vista SP2 and Windows 7 the use of [BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthenticationex) is recommended.

## Parameters

### `pbtdi`

Pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure. The Address member is used for comparison.

### `phRegHandle`

Pointer to a structure in which the registration HANDLE is stored. Call the [BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication) to close the handle.

### `pfnCallback`

Function to be called when the authentication event occurs. The function should match the prototype described in PFN_AUTHENTICATION_CALLBACK.

### `pvParam`

Optional parameter to be passed through the callback function.

## Return value

Returns ERROR_SUCCESS upon successful completion, and a valid registration handle was returned in *phRegHandle*. Any other return value indicates failure.

Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to obtain more information about the error. The following table describes a common error:

| Return code | Description |
| --- | --- |
| **ERROR_OUTOFMEMORY** | Out of memory. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)