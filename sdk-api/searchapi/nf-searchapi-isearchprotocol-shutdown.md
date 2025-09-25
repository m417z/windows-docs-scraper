# ISearchProtocol::ShutDown

## Description

Shuts down the protocol handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the protocol host to enable the protocol handler to clean up and release any associated resources.

The protocol host makes one call to this method before it exits. After this method is called, this instance will not be used any more. However, it is also possible for the protocol host process to terminate abruptly without calling this method. Protocol handlers that have persisted global states, such as registry entries and temporary files, should verify that those resources are cleaned up in the [ISearchProtocol::Init](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchprotocol-init) method before initialization.