# IVisualTreeService::RemoveChild

## Description

Removes the child element from the specified index.

## Parameters

### `parent` [in]

A handle to the collection object.

### `index` [in]

Location in *parent* collection at which to remove the child element.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. The method will fail if index is outside
of the collection range.

## Remarks

For any collection method, the caller should query the properties of a known element
and should only call this method if the property has [MetadataBit::IsValueCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit)set.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)