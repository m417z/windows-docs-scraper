# IWRdsProtocolConnection::SessionArbitrationEnumeration

## Description

Called after arbitration to allow the protocol to specify the sessions to be reconnected. The protocol extension should return **E_NOTIMPL** to use the default session arbitration.

## Parameters

### `hUserToken` [in]

A handle that represents the user token.

### `bSingleSessionPerUserEnabled` [in]

Specifies whether a user can only be associated with a single session.

### `pSessionIdArray` [out]

A pointer to a **ULONG** array that receives the disconnected session identifiers for the user. If this parameter is **NULL**, the Remote Desktop Services service is requesting the number of elements to allocate this array. Place the number of identifiers in the value pointed to by *pdwSessionIdentifierCount*.

### `pdwSessionIdentifierCount` [in, out]

A pointer to a **ULONG** value that receives the number of elements in the *pSessionIdArray* array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)