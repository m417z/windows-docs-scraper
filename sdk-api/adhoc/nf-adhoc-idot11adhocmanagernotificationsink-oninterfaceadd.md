# IDot11AdHocManagerNotificationSink::OnInterfaceAdd

## Description

Notifies the client that a new network interface card (NIC) is active.

## Parameters

### `pIAdHocInterface` [in]

A pointer to an [IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface) interface that represents the activated NIC.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocManagerNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanagernotificationsink)