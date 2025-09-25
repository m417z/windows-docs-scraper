# IDynamicConceptProviderConcept::GetConcept

## Description

The GetConcept method on a dynamic concept provider is effectively an override of the GetConcept method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). The dynamic concept provider must return an interface for the queried concept if it exists as well as any metadata associated with that concept. If the concept does not exist on the provider, that must be indicated via a false value being returned in the hasConcept argument and a successful return. Failure of this method is a failure to fetch the concept and will explicitly halt the search for the concept. Returning false for hasConcept and a successful code will continue the search for the concept through the parent model tree.

## Parameters

### `contextObject`

The instance object (this pointer) for which to get a concept.

### `conceptId`

The GUID which identifies the concept being acquired. This GUID uniquely identifies both the concept and the core interface of the concept. It is the interface id (IID) of the primary interface for a defined concept.

### `conceptInterface`

The core interface to the concept as defined by the conceptId argument is returned here.

### `conceptMetadata`

Any metadata which is associated with the concept can optionally be returned here.

### `hasConcept`

An indication of whether the dynamic provider has the concept is returned here. If the provider does not have the concept, the value false should be returned here and the method should succeed.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicConceptProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamicconceptproviderconcept)