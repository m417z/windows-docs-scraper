# IDataModelScriptManager::FindProviderForScriptType

## Description

The FindProviderForScriptExtension method searches the script manager for a provider which has claims to support a given file extension as indicated by the scriptExtension argument. If one cannot be found, this method will fail; otherwise, such script provider will be returned to the caller.

## Parameters

### `scriptType`

A string which describes the type of script being searched for (e.g.: JavaScript)

### `provider`

If a provider can be found which supports the type of script given by the scriptType argument, it will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)