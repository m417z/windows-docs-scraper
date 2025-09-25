# IVisualTreeServiceCallback::OnVisualTreeChange

## Description

Communicates the state of the visual tree when it changes.

## Parameters

### `relation` [in]

The association of a parent object with a child object.

### `element` [in]

The XAML element in the visual tree.

### `mutationType` [in]

A value that indicates whether the change was an add or remove.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVisualTreeServiceCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservicecallback)