# MMC_NOTIFY_TYPE enumeration

## Description

The
MMC_NOTIFY_TYPE enumeration defines the notifications of user actions that can be sent to a snap-in by the console's Node Manager when it calls
[IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify),
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify), or
[IExtendControlbar::ControlbarNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontrolbar-controlbarnotify). For more information, see [MMC Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-notifications).

## Constants

### `MMCN_ACTIVATE:0x8001`

A window for which the snap-in owns the result view is being activated or deactivated.

### `MMCN_ADD_IMAGES:0x8002`

The snap-in is being notified to add images for the result pane.

### `MMCN_BTN_CLICK:0x8003`

The user clicked a toolbar button.

### `MMCN_CLICK:0x8004`

Not used.

### `MMCN_COLUMN_CLICK:0x8005`

The user clicked a list view column header.

### `MMCN_CONTEXTMENU:0x8006`

Not used.

### `MMCN_CUTORMOVE:0x8007`

Items owned by the snap-in have been cut or moved.

### `MMCN_DBLCLICK:0x8008`

The user double-clicked a mouse button on a list view item or on a scope item in the result pane.

### `MMCN_DELETE:0x8009`

Sent to
inform the snap-in that an object should be deleted.

### `MMCN_DESELECT_ALL:0x800A`

Sent to the virtual list view when all items of an owner-data result pane are deselected.

### `MMCN_EXPAND:0x800B`

Sent when a scope item must be expanded or collapsed.

### `MMCN_HELP:0x800C`

Not used.

### `MMCN_MENU_BTNCLICK:0x800D`

Sent when the user clicks a snap-in defined menu button.

### `MMCN_MINIMIZED:0x800E`

Sent when a window is being minimized or maximized.

### `MMCN_PASTE:0x800F`

Notifies the snap-in's scope item to paste selected result items.

### `MMCN_PROPERTY_CHANGE:0x8010`

Informs the snap-in of property changes.

### `MMCN_QUERY_PASTE:0x8011`

Sent to determine whether the snap-in can paste items from a given data object.

### `MMCN_REFRESH:0x8012`

Sent when the refresh verb is selected.

### `MMCN_REMOVE_CHILDREN:0x8013`

Notifies the snap-in when to delete all the child items (the entire subtree) below a specified item.

### `MMCN_RENAME:0x8014`

A scope or result item must be renamed.

### `MMCN_SELECT:0x8015`

An item has been selected in either the scope pane or result pane.

### `MMCN_SHOW:0x8016`

Sent when a scope item is selected or deselected.

### `MMCN_VIEW_CHANGE:0x8017`

Sent to inform the snap-in that the view should be updated.

### `MMCN_SNAPINHELP:0x8018`

The user requested help about the snap-in.

### `MMCN_CONTEXTHELP:0x8019`

The user requested help about a selected item.

### `MMCN_INITOCX:0x801A`

Sent when a custom OCX is initialized for the first time.

### `MMCN_FILTER_CHANGE:0x801B`

Sent when the filter value for a filtered result view column has been changed.

### `MMCN_FILTERBTN_CLICK:0x801C`

The user clicked the filter button on the header control of a filtered view.

### `MMCN_RESTORE_VIEW:0x801D`

Sent when the result pane for a scope item must be restored.

### `MMCN_PRINT:0x801E`

Sent when the user clicks the **Print** button or selects the **Print** menu item.

### `MMCN_PRELOAD:0x801F`

Sent if the snap-in supports the CCF_SNAPIN_PRELOADS format.

### `MMCN_LISTPAD:0x8020`

Sent when the list control for the list view taskpad is being attached or detached.

### `MMCN_EXPANDSYNC:0x8021`

Sent when MMC requires a scope item to be expanded synchronously.

### `MMCN_COLUMNS_CHANGED:0x8022`

Sent when the user hides columns or makes columns visible in the list view.

### `MMCN_CANPASTE_OUTOFPROC:0x8023`

Sent by MMC to determine whether the snap-in supports paste operations from another MMC process.

## See also

[MMC Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-notifications)