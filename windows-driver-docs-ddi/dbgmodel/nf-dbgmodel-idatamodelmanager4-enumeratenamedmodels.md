## Description

EnumeratateNamedModels returns an enumerator which will enumerate all registered named models and their associated name.

## Parameters

### `ppEnumerator`

A pointer to an INamedModelsEnumerator interface. This enumerator can be used to enumerate all registered named models

## Return value

This method returns an HRESULT indicating the success or failure of the method call.

## Remarks

You can use this method to get an enumerator and then use the methods of the INamedModelsEnumerator interface to iterate through the named models.

## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)