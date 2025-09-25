# IWRdsRemoteFXGraphicsConnection::EnableRemoteFXGraphics

## Description

[The EnableRemoteFXGraphics method is deprecated and should not be used.
]

Queries the protocol if RemoteFX graphics should be enabled for the connection.

## Parameters

### `pEnableRemoteFXGraphics` [out]

The address of a **BOOL** variable that receives **TRUE** to enable remote FX graphics; otherwise, **FALSE**.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsRemoteFXGraphicsConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsremotefxgraphicsconnection)