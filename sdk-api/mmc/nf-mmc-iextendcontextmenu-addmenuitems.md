# IExtendContextMenu::AddMenuItems

## Description

The **IExtendContextMenu::AddMenuItems** method enables a snap-in to add items to a context menu.

## Parameters

### `piDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object of the menu to which items are added.

### `piCallback` [in]

A pointer to an
[IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback) that can add items to the context menu.

### `pInsertionAllowed` [in, out]

A value that identifies MMC-defined menu-item insertion points that can be used. This can be a combination of the following flags:

#### CCM_INSERTIONALLOWED_TOP

Items can be inserted at the top of a context menu.

#### CCM_INSERTIONALLOWED_NEW

Items can be inserted in the New submenu.

#### CCM_INSERTIONALLOWED_TASK

Items can be inserted in the All Tasks submenu.

#### CCM_INSERTIONALLOWED_VIEW

Items can be inserted in the toolbar view menu or in the
**View** submenu of the result pane context menu.

## Return value

This method can return one of these values.

## Remarks

An implementation of **IExtendContextMenu::AddMenuItems** typically reads the node type and any other parameters required by calling
IDataObject::GetDataHere on piDataObject, then adds context menu items as appropriate by calling
[IContextMenuCallback::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback-additem) on piCallback.

Your snap-in should check the pInsertionsAllowed flags for permission before attempting to add menu items at the MMC-defined insertion points. For example, a snap-in should not add menu items to CCM_INSERTIONPOINTID_PRIMARY_NEW or CCM_INSERTIONPOINTID_3RDPARTY_NEW unless the CCM_INSERTIONALLOWED_NEW flag is set.

The pInsertionsAllowed flags allow the following two features:

If the user selects a scope item and then displays its context menu, MMC will give both the snap-in's
IComponentData and
IComponent (that owns the current view) implementations the opportunity to add menu items. MMC calls the IExtendContextMenu::AddMenuItems method implemented by the snap-in's
IComponent implementation to allow the snap-in to add menu items to the
**View** menu. MMC calls the IExtendContextMenu::AddMenuItems method implemented by the snap-in's
IComponentData to allow the snap-in to add menu items to all other menus. Only the snap-in's
IComponent implementation can add items to the
**View** menu.

If the user displays a scope item's context menu without first selecting the scope item, MMC will only give the snap-in's
IComponentData implementation the opportunity to add menu items to all menus except for the
**View** menu. Consequently, the
**View** menu only appears for a scope item if the user first selects an item.

### Notes to Callers

The
AddMenuItems method should not call AddRef on either the piDataObject pointer or the piCallback pointer, nor should it call the methods of those interfaces after returning. Instead, it should make all necessary calls to the methods of those interfaces before returning. If any of these items is selected, you will be given back the pointer to IDataObject in
[IExtendContextMenu::Command](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-command), so do not keep this pointer after this method returns. You will not be notified if the menu is dismissed without any of your items being selected. In addition, do not query for alternate interfaces from piCallback because the one method, IContextMenuCallback::AddItem, should be sufficient.

## See also

[CONTEXTMENUITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-contextmenuitem)

[IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu)

[Working with Context Menus](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/working-with-context-menus)