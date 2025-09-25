# ITsSbResourcePluginStore::SetEnvironmentPropertyWithVersionCheck

## Description

Sets a property of an environment.

## Parameters

### `pEnvironment` [in]

A pointer to the environment.

### `PropertyName` [in]

The name of the property to set.

### `pProperty` [in]

A pointer to the value to set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a target or environment object is updated, the version number in the database is automatically updated. This method verifies that the version number of the object it has modified matches the internal version number in the database before attempting to save the updated object to the database.

## See also

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[SetEnvironmentProperty](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-setenvironmentproperty)