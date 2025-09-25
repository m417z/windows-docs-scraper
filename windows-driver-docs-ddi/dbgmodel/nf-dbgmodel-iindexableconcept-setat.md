# IIndexableConcept::SetAt

## Description

The SetAt method attempts to set the value at a particular N-dimensional index from within the indexed object. An indexer of N-dimensions where N is the value returned from GetDimensionality must be supported. Note that an object may be indexable in different domains by different types (e.g.: indexable via both ordinals and strings). Some indexers are read-only. In such cases, E_NOTIMPL will be returned from any call to the SetAt method.

## Parameters

### `contextObject`

The instance object (this pointer) which is being indexed is passed here.

### `indexerCount`

The number of dimensions that the object is being indexed in.

### `indexers`

An array (sized according to the indexerCount) of indices indicating where inside the instance object to access.

### `value`

The value of the element to assign at the specified indices.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
IFACEMETHOD(SetAt)(_In_ IModelObject * /*pContextObject*/,
                   _In_ ULONG64 indexerCount,
                   _In_reads_(indexerCount) IModelObject ** /*ppIndexers*/,
                   _In_ IModelObject * /*pValue*/)
{
    // We are read-only.  Do not allow Set.  An implementation would be very
    // close to the implementation of GetAt (only setting some underlying
    // value instead of fetching it)
    return E_NOTIMPL;
}
```

## See also

[IIndexableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iindexableconcept)