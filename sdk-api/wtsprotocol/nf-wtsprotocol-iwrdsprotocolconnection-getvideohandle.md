# IWRdsProtocolConnection::GetVideoHandle

## Description

Obtains the handle of the video device for the protocol.

## Parameters

### `pVideoHandle` [out]

A pointer to a handle that receives the handle of the video device.

If the protocol object is using the [IWRdsRemoteFXGraphicsConnection](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wtsprotocol/nn-wtsprotocol-iwrdsremotefxgraphicsconnection.md) interface, this method should set the contents of *pVideoHandle* to **NULL** and return **E_NOTIMPL**.

If the protocol is not using the [IWRdsRemoteFXGraphicsConnection](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wtsprotocol/nn-wtsprotocol-iwrdsremotefxgraphicsconnection.md) interface, this method should return a handle to the video miniport driver for the remote session associated with the protocol.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)