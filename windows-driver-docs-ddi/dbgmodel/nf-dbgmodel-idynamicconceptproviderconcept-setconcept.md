# IDynamicConceptProviderConcept::SetConcept

## Description

The SetConcept method on a dynamic concept provider is effectively an override of the SetConcept method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). The dynamic provider will assign the concept. This may make the object iterable, indexable, string convertible, etc... Note that a provider which does not allow the creation of concepts on it should return E_NOPTIMPL here.

## Parameters

### `contextObject`

The instance object (this pointer) on which a concept is being created.

### `conceptId`

The GUID which identifies the concept being assigned. This GUID uniquely identifies both the concept and the core interface of the concept. It is the interface id (IID) of the primary interface for a defined concept.

### `conceptInterface`

The core interface to the concept as defined by the conceptId argument.

### `conceptMetadata`

Optional metadata to be associated with the concept.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicConceptProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamicconceptproviderconcept)