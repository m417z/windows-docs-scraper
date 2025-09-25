# IWRdsProtocolConnectionCallback::BrokenConnection

## Description

Informs the Remote Desktop Services service that the client connection has been lost.

## Parameters

### `Reason` [in]

This parameter is not used.

### `Source` [in]

This parameter is not used.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnectioncallback)