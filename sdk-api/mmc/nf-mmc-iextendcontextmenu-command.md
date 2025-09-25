# IExtendContextMenu::Command

## Description

The **IExtendContextMenu::Command** method is called if one of the items you added to the context menu with
[IExtendContextMenu::AddMenuItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems) is subsequently selected. MMC calls
Command with the command ID you specified and another pointer to the same
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

## Parameters

### `lCommandID` [in]

A value that specifies the command identifier of the menu item.

### `piDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object whose context menu was displayed.

## Return value

This method can return one of these values.

## Remarks

MMC reserves negative-valued command IDs for predefined menu command IDs that it sends to a snap-in's IExtendContextMenu::Command method. The –1 command ID is the MMCC_STANDARD_VIEW_SELECT enumerator value defined in mmc.h. This is sent to IExtendContextMenu::Command when the user clicks a standard view command on the
**View** menu (Large, Small, List, or Detail). This notifies the snap-in that the user is switching away from a custom view (OCX, HTML). After getting an MMCC_STANDARD_VIEW_SELECT command, the snap-in should request a standard view the next time its
[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) method is called and not request a custom view until one of its custom view menu items is selected. If the snap-in only uses standard views or only uses custom views, it can ignore the MMCC_STANDARD_VIEW_SELECT command.

MMC sends the snap-in the MMCC_STANDARD_VIEW_SELECT command when the user clicks the
**Back** button on the toolbar. MMC uses this command to instruct the snap-in to display the result pane's previous view.

## See also

[CONTEXTMENUITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-contextmenuitem)

[IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu)

[Working with Context Menus](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/working-with-context-menus)