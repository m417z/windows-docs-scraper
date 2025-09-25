# ITsSbClientConnection::GetContext

## Description

Retrieves context information that was stored by a plug-in by using the [PutContext](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbclientconnection-putcontext) method.

## Parameters

### `contextId` [in]

A **BSTR** variable that contains the context ID.

### `context` [out, retval]

A pointer to the context information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)

[PutContext](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbclientconnection-putcontext)