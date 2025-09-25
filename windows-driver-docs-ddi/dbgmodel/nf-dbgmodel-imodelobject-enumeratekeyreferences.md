# IModelObject::EnumerateKeyReferences

## Description

The EnumerateKeyReferences method behaves similar to the EnumerateKeyValues method excepting that it returns references to the keys it enumerates (given by an [IModelKeyReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference) interface boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) instead of the value of the key. Such references can be used to get or set the underlying value of the keys.

## Parameters

### `enumerator`

An enumerator for references to all keys on the object (and all of its parent models) and metadata is returned in this argument as an [IKeyEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeyenumerator).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)