# ITsSbResourcePluginStore::GetServerState

## Description

Retrieves the state of a specified server.

## Parameters

### `PoolName` [in]

Name of the pool.

### `ServerFQDN` [in]

Fully qualified domain name (FQDN) of the server.

### `pState` [out]

On return, points to the state of the server.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)