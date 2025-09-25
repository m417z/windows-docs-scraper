# IMbnConnection::GetConnectionState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the current connection state of the device.

## Parameters

### `ConnectionState` [out, retval]

A pointer to an [MBN_ACTIVATION_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_activation_state) structure that contains the state of the connection.

### `ProfileName` [out, retval]

A pointer to a string that contains the name of the connection profile. This parameter is valid only when *ConnectionState* is **MBN_ACTIVATION_STATE_ACTIVATED**. When this string is not **NULL**, the calling application must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully.<br><br>**Note** This method can return S_OK when *ProfileName* is **NULL**. Make sure that your client is capable of handling a **NULL** *ProfileName* even if the call is successful. |
| **E_PENDING** | The activation state not available. The Mobile Broadband service is probing the device for the information. The calling application can be notified when the activation state is available by registering for the [OnConnectStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-onconnectstatechange) method of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the call state. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

This method can return S_OK when *ProfileName* is **NULL**. Make sure that your client is capable of handling a **NULL***ProfileName* even if the call is successful.

## See also

[IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection)