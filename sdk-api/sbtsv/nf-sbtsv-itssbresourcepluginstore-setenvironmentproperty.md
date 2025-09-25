# ITsSbResourcePluginStore::SetEnvironmentProperty

## Description

Sets a property of an environment.

## Parameters

### `EnvironmentName` [in]

The name of the environment.

### `PropertyName` [in]

The name of the property to set.

### `pProperty` [in]

A pointer to the value to set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)

[SetEnvironmentPropertyWithVersionCheck](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-setenvironmentpropertywithversioncheck)