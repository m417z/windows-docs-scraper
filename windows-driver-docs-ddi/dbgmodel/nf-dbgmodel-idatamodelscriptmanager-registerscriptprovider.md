# IDataModelScriptManager::RegisterScriptProvider

## Description

The RegisterScriptProvider method informs the data model that a new script provider exists which is capable of bridging a new language to the data model. When this method is called, the script manager will immediately call back the given script provider and inquire about the properties of the scripts it manages. If there is already a provider registered under the name or file extension which the given script provider indicates, this method will fail. Only a single script provider can be registered as the handler for a particular name or file extension.

## Parameters

### `provider`

The script provider being registered with the script manager. For more information about script providers, see [IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)