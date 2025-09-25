# IContextMenuProvider::EmptyMenuList

## Description

The **IContextMenuProvider::EmptyMenuList** method clears a context menu.

## Return value

This method can return one of these values.

## Remarks

[IContextMenuProvider::ShowContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenuprovider-showcontextmenu) automatically clears the context menu after that displays it. Nevertheless, it is a good practice to call
**EmptyMenuList** before beginning to build a context menu.

## See also

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)