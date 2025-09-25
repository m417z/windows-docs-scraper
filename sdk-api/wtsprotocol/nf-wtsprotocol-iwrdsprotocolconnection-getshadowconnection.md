# IWRdsProtocolConnection::GetShadowConnection

## Description

Retrieves a reference to the shadow connection object from the protocol.

## Parameters

### `ppShadowConnection` [out]

The address of [IWRdsProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowconnection) interface pointer that receives the reference to the shadow connection object. This method must add a reference to the object before returning. When the Remote Desktop Services service no longer needs the object, it will release it.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)

[IWRdsProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowconnection)