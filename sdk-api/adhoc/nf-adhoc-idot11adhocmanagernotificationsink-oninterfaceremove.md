# IDot11AdHocManagerNotificationSink::OnInterfaceRemove

## Description

Notifies the client that a network interface card (NIC) has become inactive.

## Parameters

### `Signature` [in]

A pointer to a signature that uniquely identifies the inactive NIC. For more information about signatures, see [IDot11AdHocInterface::GetDeviceSignature](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocinterface-getdevicesignature).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocManagerNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanagernotificationsink)