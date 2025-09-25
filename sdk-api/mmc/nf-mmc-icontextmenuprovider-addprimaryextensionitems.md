# IContextMenuProvider::AddPrimaryExtensionItems

## Description

The **IContextMenuProvider::AddPrimaryExtensionItems** method enables one specific extension to add items to the insertion points defined for this context menu.

## Parameters

### `piExtension` [in]

A pointer to an
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object that implements the
[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu) interface for the primary extension.

### `piDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object whose context menu is extended.

## Return value

Other values can be returned, depending on the implementation of
[IExtendContextMenu::AddMenuItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems) by the specified snap-in.

## See also

[IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback)

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)

[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu)