# IDynamicKeyProviderConcept::GetKey

## Description

The GetKey method on a dynamic key provider is largely an override of the GetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). The dynamic key provider is expected to return the value of the key and any metadata associated with that key. In the event that the key is not present (but no other error occurs), the provider must return false in the hasKey parameter and succeed with S_OK. Failing this call is considered a failure to fetch a key and will explicitly halt the search for the key through the parent model chain. Returning false in hasKey and success will continue the search for the key.

Note that it is perfectly legal for GetKey to return a boxed property accessor as the key. This would be semantically identical to the GetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) returning a property accessor.

## Parameters

### `contextObject`

The instance object (this pointer) for which to get a key.

### `key`

The name of the key being retrieved.

### `keyValue`

The value of the key as determined by the dynamic provider is returned here. If an error occurs in the fetch and an invalid HRESULT is returned, this may return extended error information. It is legal for the implementation of the GetKey method to return a property accessor ([IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)).

### `metadata`

Any metadata which is associated with the key can optionally be returned here.

### `hasKey`

An indication of whether the dynamic provider has the key or not. If the provider does not have the key, it must return false here and succeed.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicKeyProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamickeyproviderconcept)