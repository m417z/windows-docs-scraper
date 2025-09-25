# IModelObject::EnumerateKeys

## Description

Enumerates the keys within the dynamic key provider. The returned enumerator must behave as per an EnumerateKeys(...) call on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) and not as EnumerateKeyValues or any of the other enumeration variants.

Note that from the perspective of a single dynamic key provider, it is illegal to enumerate multiple keys of the same name that are physically distinct keys.

## Parameters

### `enumerator`

An enumerator for all keys on the object (and all of its parent models) and their values and metadata is returned in this argument as an [IKeyEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeyenumerator).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

The EnumerateKeys method behaves similar to the EnumerateKeyValues method excepting that it does not automatically resolve property accessors on the object. This means that if the value of a key is a property accessor, the EnumerateKeys method will return the property accessor (an IModelPropertyAccessorInterface) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) rather than automatically calling the GetValue method. This is similar to the difference between GetKey and GetKeyValue.

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)