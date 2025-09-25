# IWTSProtocolListenerCallback::OnConnected

## Description

[**IWTSProtocolListenerCallback::OnConnected** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolListenerCallback::OnConnected](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollistenercallback-onconnected).]

Notifies the Remote Desktop Services service that a client connection request has been received.
After this method is called, the Remote Desktop Services service begins the client connection sequence.

## Parameters

### `pConnection` [in]

A pointer to an [IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection) interface that represents a client connection. The Remote Desktop Services service adds a reference to this object and releases it when it closes the connection.

### `pCallback` [out]

The address of a pointer to an [IWTSProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnectioncallback) interface used by the protocol to notify the Remote Desktop Services service about the status of a client connection. The Remote Desktop Services service adds a reference to this object and the protocol must release it when the connection is closed.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolListenerCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistenercallback)