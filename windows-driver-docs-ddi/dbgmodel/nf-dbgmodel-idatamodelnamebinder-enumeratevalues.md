# IDataModelNameBinder::EnumerateValues

## Description

The EnumerateValues method enumerates the set of names and values which will bind against the object according to the rules of the BindValue method. Unlike the EnumerateKeys, EnumerateValues, and similar methods on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) which may return multiple names with the same value (for base classes, parent models, and the like), this enumerator will only return the specific set of names which will bind with BindValue and BindReference. Names will never be duplicated. Note that there is a significantly higher cost of enumerating an object via the name binder than calling the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) methods.

## Parameters

### `contextObject`

The object for which to enumerate all name bindings and their values.

### `enumerator`

An enumerator which will enumerate every name that would bind according to calls to BindValue and their values. Note that this enumerator will never duplicate names. It will only return the set of names and values which would come out of explicit calls to BindValue.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelNameBinder interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelnamebinder)