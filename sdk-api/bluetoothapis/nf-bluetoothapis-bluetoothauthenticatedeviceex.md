# BluetoothAuthenticateDeviceEx function

## Description

The **BluetoothAuthenticateDeviceEx** function sends an authentication request to a remote Bluetooth device. Additionally, this function allows for out-of-band data to be passed into the function call for the device being authenticated.

**Note** This API is supported in Windows Vista SP2 and Windows 7.

## Parameters

### `hwndParentIn` [in, optional]

The window to parent the authentication wizard. If **NULL**, the
wizard will be parented off the desktop.

### `hRadioIn` [in, optional]

A valid local radio handle or **NULL**. If **NULL**, then all radios will
be tried. If any of the radios succeed, then the call will
succeed.

### `pbtdiInout` [in, out]

A pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure describing the device being authenticated.

### `pbtOobData` [in, optional]

Pointer to device specific out-of-band data to be provided with this API call. If **NULL**, then a UI is
displayed to continue the authentication process.
If not **NULL**, no UI is displayed.

**Note** If a callback is registered using [BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthenticationex), then a UI will not be displayed.

### `authenticationRequirement` [in]

An [BLUETOOTH_AUTHENTICATION_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ne-bluetoothapis-bluetooth_authentication_requirements) value that specifies the protection required for authentication.

## Return value

Returns ERROR_SUCCESS upon successful completion; returns the following error codes upon failure:

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The user aborted the operation. |
| **ERROR_INVALID_PARAMETER** | The device structure specified in *pbdti* is invalid. |
| **ERROR_NO_MORE_ITEMS** | The device in pbtdi is already been marked as authenticated. |

## Remarks

The [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure specified by *pbtdilInOut* must contain the address of a device to authenticate. If the value of *pbtOobData* is not **NULL**, an attempt will be made to authenticate the remote device with the provided out-of-band data.

For all other types of authentication, the caller should register an authentication callback using [BluetoothRegisterForAuthenticationEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthenticationex) and then respond to the relevant authentication method using [BluetoothSendAuthenticationResponseEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsendauthenticationresponseex).

#### Examples

In the following example code a device has been found and an authentication request is sent using **BluetoothAuthenticateDeviceEx**.

```cpp
PBLUETOOTH_DEVICE_INFO pDeviceInfo;
HRESULT status;
HANDLE hEvent = NULL;

HRESULT WINAPI AuthenticateService(){

	status = BluetoothAuthenticateDeviceEx( NULL,
					        NULL,
					        pDeviceInfo,
					        NULL,
					        MITMProtectionNotRequired );

	if ( ERROR_INVALID_PARAMETER == status ) {
		// goto Cleanup;
		// ...
		// Take cleanup action here,
		// ...
	}
//
// Wait for the Authentication callback to return before trying to unregister the handle
// Use an infinite timeout since the handle to the function that sets the event is being
// deleted
//

	if ( WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE) ) {
        	status = GetLastError();
        	// goto Cleanup;
		// ...
		// Take cleanup action here,
		// ...
	}

      return status;
}
```

## See also

[BluetoothAuthenticateDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedevice)