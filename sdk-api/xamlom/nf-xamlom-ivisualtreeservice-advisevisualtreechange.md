# IVisualTreeService::AdviseVisualTreeChange

## Description

Starts listening for changes to the visual tree.

## Parameters

### `pCallback` [in]

The callback to register for mutation events.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**AdviseVisualTreeChange** should be called when the caller wants to start
listening for mutation events (changes to the visual tree). The callback will start receiving events once
the visual tree is constructed. If already constructed, the caller will immediately receive mutation events.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)