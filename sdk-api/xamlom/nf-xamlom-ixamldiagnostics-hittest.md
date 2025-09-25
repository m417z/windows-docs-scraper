# IXamlDiagnostics::HitTest

## Description

Gets all elements in the visual tree that fall within the specified rectangle.

## Parameters

### `rect` [in]

The area to hit test.

### `pCount` [out]

The size of the array.

### `ppInstanceHandles` [out]

An array containing all elements.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method performs a hit test on the XAML visual tree and will return all elements
regardless if they are enabled or invisible for hit testing. This method does not return collapsed elements as they do not participate in layout. [AdviseVisualTreeChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ivisualtreeservice-advisevisualtreechange) must be called before this method. The element does not need to be fully enclosed in the
*rect* area to be returned.

## See also

[IXamlDiagnostics](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ixamldiagnostics)