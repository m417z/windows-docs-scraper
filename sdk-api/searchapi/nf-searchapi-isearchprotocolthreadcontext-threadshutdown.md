# ISearchProtocolThreadContext::ThreadShutdown

## Description

Notifies the protocol handler that the thread is being shut down.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the protocol host is shut down, it calls this method as the last operation before terminating the filtering thread. Depending on the protocol handler, there might be some per-thread context, such as a logon session, that the protocol handler needs to clean up.