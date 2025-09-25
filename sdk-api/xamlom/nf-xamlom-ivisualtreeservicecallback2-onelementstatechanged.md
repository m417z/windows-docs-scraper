# IVisualTreeServiceCallback2::OnElementStateChanged

## Description

Communicates the state of an element in the visual tree when it changes.

## Parameters

### `element`

The XAML element in the visual tree.

### `elementState`

The state of the element.

### `context`

The path to the element.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When any XAML diagnostics API results in a resource reference becoming invalid, this callback will be notified of the invalid reference. An instance handle will be given that corresponds to an element in the tree, and a string representation of the path to the invalid reference. The grammar for the syntax is: PropertyName:Full.Dotted.TypeName[Indexer] and paths can be separated with a forward slash ("/") to be chained together.

## See also

[IVisualTreeServiceCallback2](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservicecallback2)