# IVisualTreeService::GetCollectionCount

## Description

Gets the count of a collection.

## Parameters

### `instanceHandle` [in]

A handle to the collection object.

### `pCollectionSize` [out]

The number of elements in the collection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For any collection method, the caller should query the properties of a known element
and should only call this method if the property has [MetadataBit::IsValueCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit)set.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)