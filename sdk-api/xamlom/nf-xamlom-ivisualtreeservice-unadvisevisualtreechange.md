# IVisualTreeService::UnadviseVisualTreeChange

## Description

Stops listening for changes to the visual tree.

## Parameters

### `pCallback` [in]

The callback to unregister for mutation events.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**UnadviseVisualTreeChange** should be called when the caller no longer wants to listen for
mutation events.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)