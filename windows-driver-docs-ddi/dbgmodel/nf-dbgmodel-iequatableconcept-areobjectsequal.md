# IEquatableConcept::AreObjectsEqual

## Description

Compares this object to another (of arbitrary type) for equality. If the comparison cannot be performed, E_NOT_SET should be returned.
[IEquatableConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iequatableconcept) is typically implemented by the object creators. To compare objects consider using [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)::IsEqualTo or [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)::Compare.

## Parameters

### `contextObject`

The object being compared.

### `otherObject`

The other object (of arbitrary type) that contextObject is being compared to.

### `isEqual`

Returned Boolean indicating if the two objects are equal.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

Generally speaking, you will implement (but not necessarily consume) [IEquatableConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iequatableconcept). It can be easier to call [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)::IsEqualTo or [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)::Compare and let those methods manage the concept fetch.

## See also

[IEquatableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iequatableconcept)