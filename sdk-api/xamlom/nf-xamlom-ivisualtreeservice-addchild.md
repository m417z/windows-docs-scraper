# IVisualTreeService::AddChild

## Description

Adds a child element to the collection at the specified index.

## Parameters

### `parent` [in]

A handle to the collection object.

### `child` [in]

A handle to the element to place into the collection. This can be newly created through [CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ivisualtreeservice-createinstance) or shared, such as **SolidColorBrush**.

### `index` [in]

Location in *parent* collection at which to insert *child* element.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For any collection method, the caller should query the properties of a known element
and should only call this method if the property has [MetadataBit::IsValueCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit)set.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)