# ITsSbResourcePluginStore::AddEnvironmentToStore

## Description

Adds an environment to the resource plug-in store.

## Parameters

### `pEnvironment` [in]

A pointer to an [ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment) environment object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Resource plug-ins can use this method to add an environment to the resource plug-in store.

## See also

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)