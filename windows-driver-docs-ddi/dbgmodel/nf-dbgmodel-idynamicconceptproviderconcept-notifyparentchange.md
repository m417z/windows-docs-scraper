# IDynamicConceptProviderConcept::NotifyParentChange

## Description

The NotifyParent method on a dynamic concept provider is a callback made by the core data model when a static manipulation of the object's single parent model is made. For any given parent model added, this method will be called a first time when said parent model is added and a second time if/when said parent model is removed.

## Parameters

### `parentModel`

The parent model being added or removed from the single parent model of the dynamic concept provider object.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicConceptProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamicconceptproviderconcept)