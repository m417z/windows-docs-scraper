# IContextMenuProvider::AddThirdPartyExtensionItems

## Description

The **IContextMenuProvider::AddThirdPartyExtensionItems** method enables third-party extensions to add items at specified insertion points in this context menu. MMC checks its list of snap-ins registered to extend objects of this node type and offers each (if there are any) the opportunity to extend the context menu by calling
[IExtendContextMenu::AddMenuItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems).

## Parameters

### `piDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object whose menu is extended.

## Return value

This method can return one of these values.

## See also

[IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback)

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)

[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu)