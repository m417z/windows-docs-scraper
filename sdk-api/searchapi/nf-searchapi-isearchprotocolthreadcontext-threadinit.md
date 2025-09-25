# ISearchProtocolThreadContext::ThreadInit

## Description

Initializes communication between the protocol handler and the protocol host.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After being created by the protocol host, a thread calls this method on the protocol handler to initialize communication between the protocol handler and its host. Depending on the protocol handler, the host might need to provide some per-thread context (for example, a logon session).