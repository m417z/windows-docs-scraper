# IWRdsProtocolShadowConnection::Stop

## Description

Notifies the protocol that shadowing has stopped.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values). The Remote Desktop Services service drops the connection if an error is returned.

## Remarks

The Remote Desktop Services service also changes the session state on the shadowed client to reflect the fact it is no longer being shadowed.

## See also

[IWRdsProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowconnection)