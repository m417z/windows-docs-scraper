# IDot11AdHocManagerNotificationSink::OnNetworkRemove

## Description

Notifies the client that a wireless ad hoc network destination is no longer available for connection.

## Parameters

### `Signature` [in]

A pointer to a signature that uniquely identifies the newly unavailable network. For more information about signatures, see [IDot11AdHocNetwork::GetSignature](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-getsignature).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocManagerNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanagernotificationsink)