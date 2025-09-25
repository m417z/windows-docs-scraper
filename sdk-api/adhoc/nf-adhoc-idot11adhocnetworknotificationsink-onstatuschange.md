# IDot11AdHocNetworkNotificationSink::OnStatusChange

## Description

Notifies the client that the connection status of the network has changed.

## Parameters

### `eStatus`

A [DOT11_ADHOC_NETWORK_CONNECTION_STATUS](https://learn.microsoft.com/windows/win32/api/adhoc/ne-adhoc-dot11_adhoc_network_connection_status) value that specifies the updated connection status.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## Remarks

This notification is triggered when the connection status changes as a result of connection and disconnection requests issued by the current application. It is also triggered when other applications issue successful connection and disconnection requests using the [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) methods or the [Native Wifi functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions). Connection and disconnection requests triggered by the user interface will also trigger the **OnStatusChange** notification.

## See also

[IDot11AdHocNetworkNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetworknotificationsink)