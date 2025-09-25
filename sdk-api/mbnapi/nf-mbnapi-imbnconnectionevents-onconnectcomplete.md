# IMbnConnectionEvents::OnConnectComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that signals the completion of a connection operation.

## Parameters

### `newConnection` [in]

An [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the device on which the connection operation has completed.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to identify the connection operation.

### `status` [in]

The completion status.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. |
| **E_MBN_SERVICE_NOT_ACTIVATED** | The network service subscription has expired. |
| **E_MBN_PROVIDER_NOT_VISIBLE** | The provider is not visible. This applies only to manual registration mode. |
| **E_MBN_INVALID_ACCESS_STRING** | The connection access string is not correct. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PASSWORD)** | The name or password using in the connection profile is not correct. |
| **E_MBN_VOICE_CALL_IN_PROGRESS** | An active voice call is in progress. |
| **E_MBN_MAX_ACTIVATED_CONTEXTS** | There is already an Mobile Broadband context active. The Mobile Broadband service does not currently support multiple active contexts. |
| **E_MBN_RADIO_POWER_OFF** | The device radio is off. |
| **E_MBN_PACKET_SVC_DETACHED** | No active attached packet service is available. |
| **E_MBN_ACTIVE_CONNECTION** | The device is already connected to the network. |

## Return value

This method must return **S_OK**.

## Remarks

Once an activation context is established, an application can use [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) to get the current connection state.

When the connection operation results in an error, an application can call the [GetActivationNetworkError](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnection-getactivationnetworkerror) method of the [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface to obtain network error information.

## See also

[IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents)