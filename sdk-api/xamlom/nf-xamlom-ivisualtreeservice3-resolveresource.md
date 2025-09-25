# IVisualTreeService3::ResolveResource

## Description

Resolves a resource for an element in the tree and applies the resource to the property provided by the specified property index.

## Parameters

### `resourceContext` [in]

The context of the resource.

### `resourceName` [in]

The name of the resource.

### `resourceType` [in]

The type of the resource.

### `propertyIndex` [in]

The index of the property to apply the resource to.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If no resource was found, or the resource type was invalid, [IVisualTreeServiceCallback2](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservicecallback2) will be notified.

Call [GetDictionaryItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ivisualtreeservice3-getdictionaryitem) to get a *resourceContext* and give better resolution context for **ResolveResource**.

## See also

[IVisualTreeService3](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice3)