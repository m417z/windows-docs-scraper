# BluetoothAuthenticateDevice function

## Description

The **BluetoothAuthenticateDevice** function sends an authentication request to a remote Bluetooth device.

**Note** When developing for Windows Vista SP2 and Windows 7 the use of [BluetoothAuthenticateDeviceEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedeviceex) is recommended.

## Parameters

### `hwndParent`

A window to be the parent of the Authentication wizard. If set to **NULL**, the wizard is removed from the desktop.

### `hRadio`

A valid local radio handle, or **NULL**. If **NULL**, authentication is attempted on all local radios; if any radio succeeds, the function call succeeds.

### `pbtbi`

A structure of type [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) that contains the record of the Bluetooth device to be authenticated.

### `pszPasskey`

A Personal Identification Number (PIN) to be used for device authentication. If set to **NULL**, the user interface is displayed and the user must follow the authentication process provided in the user interface. If *pszPasskey* is not **NULL**, no user interface is displayed. If the passkey is not **NULL**, it must be a **NULL**-terminated string. For more information, see the Remarks section.

### `ulPasskeyLength`

The size, in characters, of *pszPasskey*. The size of *pszPasskey* must be less than or equal to **BLUETOOTH_MAX_PASSKEY_SIZE**.

## Return value

Returns **ERROR_SUCCESS** upon successful completion.

Common errors are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The user canceled the operation. |
| **ERROR_INVALID_PARAMETER** | The device structure in the *pbtdi* parameter is not valid. |
| **ERROR_NO_MORE_ITEMS** | The device pointed to by *pbtdi* is already marked as authenticated. |

## Remarks

Some remote Bluetooth devices can only accept numeric passkeys. There is no way to identify which devices only accept numeric passkeys in advance.

The Bluetooth authentication process has two modes: Wizard mode and Transparent mode.

Wizard mode is started when *pszPasskey* is set to **NULL**, and the Bluetooth Connection Wizard is started. The user is prompted to enter a passkey as a step in the wizard, after which the authentication request is sent. The user interface displays whether the authentication attempt succeeds or fails, and provides the user with an opportunity to reattempt a failed authentication.

Transparent mode is started when *pszPasskey* is not **NULL**. In Transparent mode the authentication request is sent to the remote Bluetooth device without displaying any user interface. In Transparent mode, the Bluetooth status code is mapped to a Win32 error code; the following table lists this mapping information.

| Bluetooth status code | Win32 error code |
| --- | --- |
| BTH_ERROR_SUCCESS | ERROR_SUCCESS |
| BTH_ERROR_NO_CONNECTION | ERROR_DEVICE_NOT_CONNECTED |
| BTH_ERROR_PAGE_TIMEOUT | WAIT_TIMEOUT |
| BTH_ERROR_HARDWARE_FAILURE | ERROR_GEN_FAILURE |
| BTH_ERROR_AUTHENTICATION_FAILURE | ERROR_NOT_AUTHENTICATED |
| BTH_ERROR_MEMORY_FULL | ERROR_NOT_ENOUGH_MEMORY |
| BTH_ERROR_CONNECTION_TIMEOUT | WAIT_TIMEOUT |
| BTH_ERROR_LMP_RESPONSE_TIMEOUT | WAIT_TIMEOUT |
| BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS | ERROR_REQ_NOT_ACCEP |
| BTH_ERROR_PAIRING_NOT_ALLOWED | ERROR_ACCESS_DENIED |
| BTH_ERROR_UNSPECIFIED_ERROR | ERROR_NOT_READY |
| BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION | ERROR_VC_DISCONNECTED |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BluetoothAuthenticateDeviceEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedeviceex)

[BluetoothAuthenticateMultipleDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[BluetoothEnableDiscovery](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)

[BluetoothEnableIncomingConnections](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenableincomingconnections)

[BluetoothIsConnectable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisconnectable)

[BluetoothIsDiscoverable](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothisdiscoverable)

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothSendAuthenticationResponse](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponse)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)