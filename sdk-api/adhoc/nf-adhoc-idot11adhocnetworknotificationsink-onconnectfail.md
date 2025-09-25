# IDot11AdHocNetworkNotificationSink::OnConnectFail

## Description

Notifies the client that a connection attempt failed. The connection attempt may have been initiated by the client itself or by another application using the [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) methods or the [Native Wifi functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions).

## Parameters

### `eFailReason`

A [DOT11_ADHOC_CONNECT_FAIL_REASON](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_connect_fail_reason) value that specifies the reason the connection attempt failed.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocNetworkNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetworknotificationsink)