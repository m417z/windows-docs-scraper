# IWRdsRemoteFXGraphicsConnection::GetVirtualChannelTransport

## Description

[The GetVirtualChannelTransport method is deprecated and should not be used.
]

Retrieves the virtual channel transport object.

## Parameters

### `ppTransport` [out]

A pointer to a returned object pointer that represents the virtual channel transport. This is a pointer to the [IWRdsGraphicsChannelManager](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelmanager) interface.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsRemoteFXGraphicsConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsremotefxgraphicsconnection)