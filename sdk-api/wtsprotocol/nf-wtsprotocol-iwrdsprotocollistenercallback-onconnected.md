# IWRdsProtocolListenerCallback::OnConnected

## Description

Notifies the Remote Desktop Services service that a client connection request has been received.
After this method is called, the Remote Desktop Services service begins the client connection sequence.

## Parameters

### `pConnection` [in]

A pointer to an [IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection) interface that represents a client connection. The Remote Desktop Services service adds a reference to this object and releases it when it closes the connection.

### `pWRdsConnectionSettings` [in]

A pointer to a [WRDS_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings) structure that contains the connection settings for the remote session.

### `pCallback` [out]

The address of a pointer to an [IWRdsProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnectioncallback) interface used by the protocol to notify the Remote Desktop Services service about the status of a client connection. The Remote Desktop Services service adds a reference to this object and the protocol must release it when the connection is closed.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolListenerCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistenercallback)