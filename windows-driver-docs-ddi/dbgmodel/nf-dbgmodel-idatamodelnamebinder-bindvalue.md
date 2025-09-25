# IDataModelNameBinder::BindValue

## Description

The BindValue method performs the equivalent of contextObject.name on the given object according to a set of binding rules. The result of this binding is a value. As a value, the underlying script provider cannot use the value to perform assignment back to name.

## Parameters

### `contextObject`

The object to bind a name against.

### `name`

The name to bind in the context of contextObject.

### `value`

The value of name in the context of contextObject is returned. As a value binding, this cannot be used to support assignment back to name.

### `metadata`

Any metadata optionally associated with name is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelNameBinder interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelnamebinder)