# ITsSbResourcePluginStore::TestAndSetServerState

## Description

Conditionally sets a new state on a server.

## Parameters

### `PoolName` [in]

Name of the pool.

### `ServerFQDN` [in]

Fully qualified domain name (FQDN) of the server.

### `NewState` [in]

The state to set.

### `TestState` [in]

If set to **TARGET_UNKNOWN** or the current state of the server, the server will be set as specified in the *NewState* parameter.

### `pInitState` [out]

On return, points to the previous state of the server.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)