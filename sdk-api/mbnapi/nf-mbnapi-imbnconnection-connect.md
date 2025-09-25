# IMbnConnection::Connect

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Establishes a data connection.

## Parameters

### `connectionMode` [in]

An [MBN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_connection_mode) value that specifies the mode of the connection.

### `strProfile` [in]

Contains the profile designator.

### `requestID` [out]

A pointer to a unique request ID returned by the Mobile Broadband service to identify this asynchronous request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **E_INVALIDARG** | An invalid profile name was specified or the *strProfile* argument is not compliant to XML profile schema |
| **E_MBN_MAX_ACTIVATED_CONTEXTS** | There is already an active Mobile Broadband context. Multiple active contexts are not supported. |

## Remarks

The [Connect](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) method is used to activate a connection context for the device. The Mobile Broadband service currently supports at most one active context. Activation of the context will also result in L2 connection also being established. Similarly, deactivation of a context will result in disconnection of the physical data connection to the mobile network.

If the device is not in the packet-attached state at the time of calling this operation then the Mobile Broadband service will implicitly packet attach the device before issuing the connect request to the device. If there is any packet service state change then application will be notified by a call to the [OnPacketServiceStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onpacketservicestatechange) method of the [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents) interface.

If *connectionMode* is set to **MBN_CONNECTION_MODE_PROFILE**, then *strProfile* represents the name of the profile for the device. If set to **MBN_CONNECTION_MODE_TMP_PROFILE**, then *strProfile* represents the XML representation of the profile. A calling application can use [IMbnConnectionProfileManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanager) to get a list of connection profiles stored in the device.

This is an asynchronous operation that will return immediately. If this method returns successfully, then the Mobile Broadband service will call the [OnConnectComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-onconnectcomplete) method of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents) when the operation is complete.

Windows 8 and later versions of Windows: A Windows Store app may use [Connect](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) with only the [MBN_CONNECTION_MODE_TMP_PROFILE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_connection_mode)*connectionMode* and the *strProfile* parameter set to an XML representation of the profile. This implies that the connection is of a temporary nature and not saved for future use by the system.

## See also

[IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection)