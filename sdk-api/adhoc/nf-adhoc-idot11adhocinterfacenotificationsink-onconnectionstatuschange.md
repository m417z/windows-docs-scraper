# IDot11AdHocInterfaceNotificationSink::OnConnectionStatusChange

## Description

Notifies the client that the connection status of the network associated with the NIC has changed.

## Parameters

### `eStatus`

A pointer to a [DOT11_ADHOC_NETWORK_CONNECTION_STATUS](https://learn.microsoft.com/windows/win32/api/adhoc/ne-adhoc-dot11_adhoc_network_connection_status) value that specifies the new connection state.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## Remarks

This notification is triggered when the connection status changes as a result of connection and disconnection requests issued by the current application. It is also triggered when other applications issue successful connection and disconnection requests using the [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) methods or the [Native Wifi functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions).

## See also

[IDot11AdHocInterfaceNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterfacenotificationsink)