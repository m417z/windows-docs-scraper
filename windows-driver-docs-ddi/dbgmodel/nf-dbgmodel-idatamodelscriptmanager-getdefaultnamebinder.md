# IDataModelScriptManager::GetDefaultNameBinder

## Description

The GetDefaultNameBinder method returns the data model's default script name binder. A name binder is a component which resolves a name within the context of an object. For instance, given the expression "foo.bar", a name binder is called upon to resolve the name bar in the context of object foo. The binder returned here follows a set of default rules for the data model. Script providers can use this binder to provide consistency in name resolution across providers.

## Parameters

### `ppNameBinder`

The default name binder will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

The [IDataModelNameBinder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelnamebinder) topic provides more information on how a name binder can associate names in a context with objects or symbols.

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)