# ITsSbResourcePluginStore::ReleaseTargetLock

## Description

Releases a lock on a target.

## Parameters

### `pContext` [in]

A pointer to the context returned by the [AcquireTargetLock](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-acquiretargetlock) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)