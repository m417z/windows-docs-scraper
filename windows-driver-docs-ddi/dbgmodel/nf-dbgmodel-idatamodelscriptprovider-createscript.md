# IDataModelScriptProvider::CreateScript

## Description

The CreateScript method is called to create a new script. The script provider must return a new and empty script represented by the returned [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript) interface whenever this method is called. Note that this method is called regardless of whether a user interface is creating a new blank script for editing by the user or whether the debugger application is loading a script from disk. The provider does not get involved in file I/O. It merely handles the requests from the hosting application via streams passed to methods on [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript).

## Parameters

### `script`

A new and empty script will be returned here as a component implementing the [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider)