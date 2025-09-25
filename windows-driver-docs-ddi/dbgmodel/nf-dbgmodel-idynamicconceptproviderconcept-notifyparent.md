# IDynamicConceptProviderConcept::NotifyParent

## Description

The NotifyParent call on a dynamic concept provider is used by the core data model to inform the dynamic provider of the single parent model which is created to allow for bridging the "multiple parent models" paradigm of the data model to more dynamic languages. Any manipulation of that single parent model will cause further notifications to the dynamic provider. Note that this callback is made immediately upon assignment of the dynamic concept provider concept.

## Parameters

### `parentModel`

The single parent model created by the data model to help bridge the multiple parent paradigm of the data model to more dynamic languages. The dynamic provider should save this argument as it will only be notified of this once upon assignment of the dynamic concept provider concept.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDynamicConceptProviderConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idynamicconceptproviderconcept)