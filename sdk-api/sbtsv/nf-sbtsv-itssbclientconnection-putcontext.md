# ITsSbClientConnection::PutContext

## Description

Can be used by plug-ins to store context information specific to the connection.

## Parameters

### `contextId` [in]

A **BSTR** variable that contains the context ID. We recommend using unique identifiers as context IDs to avoid collisions between plug-ins. A client connection object can be used by more than one plug-in.

### `context` [in]

The context information to store.

### `existingContext` [out, optional]

Existing context information for the supplied context ID, if any, is returned in this parameter. The existing information is overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins can use the client connection object to store context information that is specific to a connection request. This allows plug-ins to remain stateless and rely exclusively on state information stored by connection requests. Plug-ins that use this method can also register for connection request notifications. Contexts can be deleted upon receipt of CONNECTION_REQUEST_FAILED, CONNECTION_REQUEST_TIMEDOUT, or CONNECTION_REQUEST_SUCCEEDED notifications. These notifications indicate that the connection request is about to be deleted.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)