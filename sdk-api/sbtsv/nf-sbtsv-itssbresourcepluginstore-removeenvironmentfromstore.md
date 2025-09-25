# ITsSbResourcePluginStore::RemoveEnvironmentFromStore

## Description

Removes the specified environment from the resource plug-in store.

## Parameters

### `EnvironmentName` [in]

The name of the environment to remove.

### `bIgnoreOwner` [in, optional]

Set **TRUE** to ignore ownership of the environment; **FALSE**
otherwise.

**Windows Server 2012 R2 and Windows Server 2012:** This parameter is not supported before Windows Server 2016.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)