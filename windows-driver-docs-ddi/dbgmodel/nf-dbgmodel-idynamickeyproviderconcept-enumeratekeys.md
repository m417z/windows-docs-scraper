# IDynamicKeyProviderConcept::EnumerateKeys

## Description

The EnumerateKeys method on a dynamic key provider is effectively an override of the EnumerateKeys method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This enumerates all the keys in the dynamic provider. The returned enumerator has several restrictions that must be honored by the implementation:

- It must behave as a call to EnumerateKeys and not EnumerateKeyValues or EnumerateKeyReferences. It must return the key values not resolving any underlying property accessors (if such concept exists in the provider).
- From the perspective of a single dynamic key provider, it is illegal to enumerate multiple keys of the same name that are physically distinct keys. This can happen on different providers that are attached through the parent model chain, but it cannot happen from the perspective of a single provider.

## Parameters

### `contextObject`

The instance object (this pointer) for which to enumerate keys.

### `ppEnumerator`

An enumerator for all keys on the dynamic provider must be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicKeyProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamickeyproviderconcept)