# IDataModelNameBinder::BindReference

## Description

The BindReference method is similar to BindValue in that it also performs the equivalent of contextObject.name on the given object according to a set of binding rules. The result of the binding from this method is, however, a reference instead of a value. As a reference, the script provider can utilize the reference to perform assignment back to name.

## Parameters

### `contextObject`

The object to bind a name against.

### `name`

The name to bind in the context of contextObject.

### `reference`

A reference to name in the context of contextObject is returned. As a reference binding, this can be used to support assignment back to name.

### `metadata`

Any metadata optionally associated with name is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelNameBinder interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelnamebinder)