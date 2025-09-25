# IIterableConcept::GetDefaultIndexDimensionality

## Description

The GetDefaultIndexDimensionality method returns the number of dimensions to the default index. If an object is not indexable, this method should return 0 and succeed (S_OK). Any object which returns a non-zero value from this method is declaring support for a protocol contract which states:

- The object supports the indexable concept via support of [IIndexableConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iindexableconcept)
- The GetNext method of the [IModelIterator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodeliterator) returned from the GetIterator method of the iterable concept will return a unique default index for each produced element. Such index will have the number of dimensions as indicated here.
- Passing the indices returned from the GetNext method of the [IModelIterator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodeliterator) to the GetAt method on the indexable concept ([IIndexableConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iindexableconcept)) will refer to the same object that GetNext produced. The same value is returned.

## Parameters

### `contextObject`

The instance (this pointer) being queried.

### `dimensionality`

The number of dimensions of the default indexer is returned here. A return value of zero indicates that the object is not indexable.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
IFACEMETHOD(GetDefaultIndexDimensionality)(_In_ IModelObject * /*pContextObject*/,
                                           _Out_ ULONG64 *pDimensionality)
{
    // If the object is not indexable, pDimensionality should be 0 and the
    // method should return S_OK.  Here, the object is indexable in one dimension.
    // Providing this information requires that our iterator return these
    // 1D indexes and that we have an indexer which accepts them.
    *pDimensionality = 1;
    return S_OK;
}
```

## See also

[IIterableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iiterableconcept)