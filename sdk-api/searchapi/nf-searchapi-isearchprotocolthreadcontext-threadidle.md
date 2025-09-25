# ISearchProtocolThreadContext::ThreadIdle

## Description

Notifies the protocol handler that the filtering thread is idle, so that the protocol handler can clean up any cache it might have built up.

## Parameters

### `dwTimeElaspedSinceLastCallInMS` [in]

Type: **DWORD**

Passes the idle time, in milliseconds, to the protocol handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called when the filtering thread is waiting for new requests from the indexer service so the protocol handler can use this idle time to clean up.