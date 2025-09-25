# IConsole::SelectScopeItem

## Description

Selects the given scope item.

## Parameters

### `hScopeItem` [in]

A handle to the item in the scope pane to be selected.

## Return value

This method can return one of these values.

## Remarks

Use this method to reselect the currently selected scope item or to select another scope item.

You can have a single scope item with several different views available, for example, several OLE custom control (OCX) views and the default list view. When the user selects a different view from a menu, the snap-in receives the command and should then call
**SelectScopeItem** to reselect the item.
[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) can then return the new view type.

If
**SelectScopeItem** is called by the snap-in in its [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification handler, MMC will not select the specified scope item, even though
**SelectScopeItem** may return **S_OK**.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)