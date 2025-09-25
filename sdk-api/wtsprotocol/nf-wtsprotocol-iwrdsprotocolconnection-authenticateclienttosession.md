# IWRdsProtocolConnection::AuthenticateClientToSession

## Description

Specifies a session that the connection should be reconnected to.

## Parameters

### `SessionId` [out]

A pointer to a [WRDS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that uniquely identifies the session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Upon receiving an error, the Remote Desktop Services service continues the connection sequence.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)