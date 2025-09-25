# IWTSProtocolConnection::SessionArbitrationEnumeration

## Description

[**IWTSProtocolConnection::SessionArbitrationEnumeration** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::SessionArbitrationEnumeration](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-sessionarbitrationenumeration).]

Retrieves a collection of session IDs for reconnection.

## Parameters

### `hUserToken` [in]

A pointer to a user token handle.

### `bSingleSessionPerUserEnabled` [in]

A Boolean value that specifies whether a user can be associated with, at most, one session.

### `pSessionIdArray` [out]

A pointer to an array of integers that contains the disconnected session IDs for the user.

### `pdwSessionIdentifierCount` [in, out]

A pointer to an integer that specifies the number of disconnected session IDs referenced by the *pSessionIdArray* parameter.

## Remarks

The Remote Desktop Services service calls this method to find existing sessions that this user can reconnect to. If this method returns an **HRESULT** error code or it does not return any session IDs, the Remote Desktop Services service performs arbitration itself.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)