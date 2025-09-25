# IContextMenuProvider::ShowContextMenu

## Description

The **IContextMenuProvider::ShowContextMenu** method displays a context menu.

## Parameters

### `hwndParent` [in]

A handle to the parent window in which the context menu is displayed.

### `xPos` [in]

A value, in screen coordinates, that specifies the horizontal location of the upper-left corner of the context menu, in screen coordinates.

### `yPos` [in]

A value, in screen coordinates, that specifies the vertical location of the upper-left corner of the context menu.

### `plSelected` [out]

A value that specifies the ICommandID value (as passed to
[IContextMenuCallback::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback-additem)) of the selected menu item. If this is zero, either none of the context menu items were selected or the selected context menu item was added by an extension. If an extension item was selected,
ShowContextMenu notifies the extension by calling
[IExtendContextMenu::Command](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-command).

## Return value

This method can return one of these values.

## Remarks

ShowContextMenu automatically clears the context menu after that displays it. A best practice is to call
[IContextMenuProvider::EmptyMenuList](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenuprovider-emptymenulist) before beginning to build a context menu.

## See also

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)