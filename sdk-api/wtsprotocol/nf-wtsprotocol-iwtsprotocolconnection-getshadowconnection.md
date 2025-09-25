# IWTSProtocolConnection::GetShadowConnection

## Description

[**IWTSProtocolConnection::GetShadowConnection** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::GetShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getshadowconnection).]

Retrieves a [IWTSProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolshadowconnection) object from the protocol. The method must add a reference to the object before returning. When the Remote Desktop Services service has finished the licensing process, it will release the reference.

## Parameters

### `ppShadowConnection` [out]

 The address of a pointer to an [IWTSProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolshadowconnection) interface.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)