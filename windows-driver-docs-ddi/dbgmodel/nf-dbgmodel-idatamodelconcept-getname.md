# IDataModelConcept::GetName

## Description

If a given data model is registered under a default name via the RegisterNamedModel method, the registered data model's [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) interface must return that name from this method. Note that it is perfectly legitimate for a model to be registered under multiple names (the default or best one should be returned here). A model may be completely unnamed (so long as it is not registered under a name). In such circumstances, the GetName method should return E_NOTIMPL.

## Parameters

### `modelName`

The model name should be returned in this argument as a string allocated via the SysAllocString method.

## Return value

This method returns HRESULT which indicates success or failure. A model which is unnamed should return E_NOTIMPL.

## Remarks

## See also

[IDataModelConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept)