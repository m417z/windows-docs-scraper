# IVisualTreeService3::RemoveDictionaryItem

## Description

 Removes an item from a [ResourceDictionary](https://learn.microsoft.com/dotnet/api/system.windows.resourcedictionary?view=netframework-4.8&preserve-view=true), and re-resolves all elements in the tree that reference a resource with the specified key.

## Parameters

### `dictionaryHandle` [in]

The dictionary to remove the resource from.

### `resourceKey` [in]

The key of the resource to remove.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any invalid resource references will result in the value being cleared, and [IVisualTreeServiceCallback2](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservicecallback2) will be notified.

## See also

[IVisualTreeService3](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice3)