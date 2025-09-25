# IDot11AdHocManagerNotificationSink::OnNetworkAdd

## Description

Notifies the client that a new wireless ad hoc network destination is in range and available for connection.

## Parameters

### `pIAdHocNetwork` [in]

A pointer to an [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) interface that represents the new network.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocManagerNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanagernotificationsink)