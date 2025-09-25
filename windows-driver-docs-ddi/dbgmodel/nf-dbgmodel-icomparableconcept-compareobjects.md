# IComparableConcept::CompareObjects

## Description

 Compares this object to another (of arbitrary type). If the comparison cannot be performed, E_NOT_SET should be returned.
The return value passed in comparison result has the following meaning:

```text
< 0 : contextObject < otherObject

0 : contextObject == otherObject

> 0 : contextObject > otherObject
```

## Parameters

### `contextObject`

The object which is being compared. This should be the same object from which the comparable concept was acquired.

### `otherObject`

The object to compare to.

### `comparisonResult`

The result of the comparison will be returned here. If the returned value is less than 0, contextObject is less than otherObject. If the returned value is zero, they are equal. If the returned value is greater than zero, contextObject is greater than otherObject.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IComparableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-icomparableconcept)