# IComponent::Notify

## Description

The **IComponent::Notify** method notifies the snap-in of actions taken by the user.

## Parameters

### `lpDataObject` [in]

A pointer to the data object of the currently selected item.

### `event` [in]

Identifies an action taken by a user. **IComponent::Notify** can receive the following notifications:

[MMCN_ACTIVATE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-activate)

[MMCN_ADD_IMAGES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-add-images)

[MMCN_BTN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-btn-click)

[MMCN_COLUMN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-column-click)

[MMCN_COLUMNS_CHANGED](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-columns-changed)

[MMCN_CONTEXTHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-contexthelp)

[MMCN_DBLCLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-dblclick)

[MMCN_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-delete)

[MMCN_DESELECT_ALL](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-deselect-all)

[MMCN_FILTERBTN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filterbtn-click)

[MMCN_FILTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filter-change)

[MMCN_INITOCX](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-initocx)

[MMCN_LISTPAD](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-listpad)

[MMCN_MINIMIZED](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-minimized)

[MMCN_PASTE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-paste)

[MMCN_PRINT](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-print)

[MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change)

[MMCN_QUERY_PASTE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-query-paste)

[MMCN_REFRESH](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-refresh)

[MMCN_RENAME](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-rename)

[MMCN_RESTORE_VIEW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-restore-view)

[MMCN_SELECT](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-select)

[MMCN_SHOW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-show)

[MMCN_SNAPINHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-snapinhelp)

[MMCN_VIEW_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-view-change)

### `arg`

Depends on the notification type.

### `param`

Depends on the notification type.

## Return value

This method can return one of these values.

## Remarks

For more information, see the individual notifications. The snap-in should return **S_FALSE** for any notification it does not handle.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)

[IExtendControlbar::ControlbarNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontrolbar-controlbarnotify)