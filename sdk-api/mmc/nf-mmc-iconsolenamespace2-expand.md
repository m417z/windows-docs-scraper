# IConsoleNameSpace2::Expand

## Description

The **IConsoleNameSpace2::Expand** method enables the snap-in to expand an item in the namespace without visibly expanding the item in the scope pane.

## Parameters

### `hItem` [in]

A handle to the item to expand.

## Return value

This method can return one of these values.

## Remarks

**IConsoleNameSpace2::Expand** should be used to expand a specified item for the purpose of enumerating the child items of that item. Be aware that you must call **IConsoleNameSpace2::Expand** before inserting an item as a child item in the scope pane.

For example, if a snap-in must place a child item beneath a parent item at a specific position (such as the top of a child item list), the snap-in should use this method to expand the item to find the exact position in which to place a child item. The snap-in could also use this method to call
[IConsoleNameSpace2::GetChildItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getchilditem) on a child item of an item that has not been expanded (either by a previous call to **IConsoleNameSpace2::Expand** or by the user clicking the plus sign in the scope pane) to expand that item for the purpose of enumerating its children.

**IConsoleNameSpace2::Expand** does not visibly expand the item in the tree displayed in the scope pane in the console. A snap-in uses
[IConsole2::Expand](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsole2-expand) to visibly expand or collapse an item in the scope pane. This method sends an [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification to
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) if and only if the item has not been previously expanded.

## See also

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)