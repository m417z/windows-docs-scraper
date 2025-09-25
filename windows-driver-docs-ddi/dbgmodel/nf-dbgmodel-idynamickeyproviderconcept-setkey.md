# IDynamicKeyProviderConcept::SetKey

## Description

The SetKey method on a dynamic key provider is effectively an override of the SetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This sets a key in the dynamic provider. It is effectively the creation of a new property on the provider. Note that a provider which does not support any notion of something like the creation of expando properties should return E_NOTIMPL here.

## Parameters

### `contextObject`

The instance object (this pointer) for which to set a key.

### `key`

The name of the key to set.

### `keyValue`

The value of the key to set.

### `metadata`

Optional metadata to be associated with the (newly created) key.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicKeyProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamickeyproviderconcept)