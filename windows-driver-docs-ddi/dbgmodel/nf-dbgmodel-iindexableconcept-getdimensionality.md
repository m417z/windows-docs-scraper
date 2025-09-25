# IIndexableConcept::GetDimensionality

## Description

The GetDimensionality method returns the number of dimensions that the object is indexed in. Note that if the object is both iterable and indexable, the implementation of GetDefaultIndexDimensionality must agree with the implementation of GetDimensionality as to how many dimensions the indexer has.

## Parameters

### `contextObject`

The instance object (this pointer) which is being indexed is passed here.

### `dimensionality`

The number of dimensions that the object is indexed in is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
IFACEMETHOD(GetDimensionality)(_In_ IModelObject * /*pContextObject*/,
                               _Out_ ULONG64 *pDimensionality)
{
    // If the object is iterable, the value returned here **MUST** match
    // what is returned from GetDefaultIndexDimensionality.
    *pDimensionality = 1;
    return S_OK;
}
```

## See also

[IIndexableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iindexableconcept)