# IVisualTreeService::GetCollectionElements

## Description

Gets the elements in a collection.

## Parameters

### `instanceHandle` [in]

A handle to the collection object.

### `startIndex` [in]

The index in the collection to start getting elements from.

### `pElementCount` [in, out]

The count of elements in the returned array.

### `ppElementValues` [out]

An array of elements returned from the collection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For any collection method, the caller should query the properties of a known element
and should only call this method if the property has [MetadataBit::IsValueCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit)set.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)