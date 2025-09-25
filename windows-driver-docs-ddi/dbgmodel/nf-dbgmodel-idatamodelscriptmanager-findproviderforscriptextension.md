# IDataModelScriptManager::FindProviderForScriptExtension

## Description

The FindProviderForScriptExtension method searches the script manager for a provider which has claims to support a given file extension as indicated by the scriptExtension argument. If one cannot be found, this method will fail; otherwise, such script provider will be returned to the caller.

## Parameters

### `scriptExtension`

The file extension for which to find a scriptprovider (e.g.: js).

### `provider`

If a provider can be found which handles the file extension given by the scriptExtension argument, it will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)