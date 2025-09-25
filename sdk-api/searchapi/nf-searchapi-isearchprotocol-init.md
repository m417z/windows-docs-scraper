# ISearchProtocol::Init

## Description

Initializes a protocol handler.

## Parameters

### `pTimeoutInfo` [in]

Type: **[TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info)***

Pointer to a [TIMEOUT_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-timeout_info) structure that contains information about connection time-outs.

### `pProtocolHandlerSite` [in]

Type: **[IProtocolHandlerSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iprotocolhandlersite)***

Pointer to an [IProtocolHandlerSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iprotocolhandlersite) interface that enables protocol handlers to access [IFiltear](https://learn.microsoft.com/windows-hardware/test/hlk/api/ifilter-interface) within the filter host.

### `pProxyInfo` [in]

Type: **[PROXY_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-proxy_info)***

Pointer to a [PROXY_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-proxy_info) structure that contains information about the proxy settings necessary for accessing items in the content source.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After the protocol handler is [created](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance), this method is called to perform any initialization specific to the protocol handler. This method is not called again.

Because the protocol host may unexpectedly terminate before calling [ISearchProtocol::ShutDown](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchprotocol-shutdown), protocol handlers with persistent information, such as temporary files and registry entries, should do an initial clean-up of resources previously opened in this method before starting the current instance.