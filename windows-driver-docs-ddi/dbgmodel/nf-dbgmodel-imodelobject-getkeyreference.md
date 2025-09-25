# IModelObject::GetKeyReference

## Description

If the object or one of its parent models has a key named according to the argument 'key', this will return a reference to that key (and optionally the *present* metadata associated with that key).

## Parameters

### `key`

The name of the key to get a value for.

### `objectReference`

The object reference.

### `metadata`

The metadata store associated with this key will be optionally returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)