# IVisualTreeService3::GetDictionaryItem

## Description

Gets an item from a [ResourceDictionary](https://learn.microsoft.com/dotnet/api/system.windows.resourcedictionary?view=netframework-4.8&preserve-view=true).

## Parameters

### `dictionaryHandle` [in]

The dictionary to get the resource from.

### `resourceName` [in]

The name of the resource to get.

### `resourceIsImplicitStyle` [in]

**true** if the resource is an implicit style; otherwise, **false**.

### `resourceHandle` [out]

The resource that was retrieved.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVisualTreeService3](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice3)