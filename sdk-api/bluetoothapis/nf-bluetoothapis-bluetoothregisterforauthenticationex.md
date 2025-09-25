# BluetoothRegisterForAuthenticationEx function

## Description

The **BluetoothRegisterForAuthenticationEx** function registers an application for a pin request, numeric comparison and callback function.

**Note** This API is supported in Windows Vista SP2 and Windows 7.

## Parameters

### `pbtdiIn` [in, optional]

A pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure that specifies the bluetooth address to be utilized for comparison.

### `phRegHandleOut` [out]

A pointer to a **HBLUETOOTH_AUTHENTICATION_REGISTRATION** handle associated with the registered application. Call [BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication) to close
the handle.

### `pfnCallbackIn` [in, optional]

The function that will be called when the authentication event occurs. This function should match the prototype of [PFN_AUTHENTICATION_CALLBACK_EX](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_authentication_callback_ex).

### `pvParam` [in, optional]

Optional parameter to be passed through to the callback function specified by *pfnCallbackIn*. This parameter can be anything the application is required to define.

## Return value

Returns ERROR_SUCCESS upon successful completion; returns the following error codes upon failure:

| Return code | Description |
| --- | --- |
| **ERROR_OUTOFMEMORY** | Out of memory. |
| **Win32 Error** | The registration handle that was provided is invalid. |

## Remarks

The caller must provide a valid callback address and must unregister the callback once notification is no longer required. The deregistration of an authenticated device can be accomplished by calling [BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication).

In scenarios where an application registers for authentication more than once, only the first callback function registered via this function will be called in the application while authentication is in progress.

## See also

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)

[BluetoothUnregisterAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothunregisterauthentication)