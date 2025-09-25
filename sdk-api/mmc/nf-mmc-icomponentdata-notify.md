# IComponentData::Notify

## Description

The **IComponentData::Notify** method notifies the snap-in of actions performed by the user.

## Parameters

### `lpDataObject` [in]

A pointer to the data object of the currently selected item.

### `event` [in]

Identifies an action taken by a user. **IComponentData::Notify** can receive the following notifications:

[MMCN_BTN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-btn-click)

[MMCN_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-delete)

[MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand)

[MMCN_EXPANDSYNC](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expandsync)

[MMCN_PRELOAD](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-preload)

[MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change)

[MMCN_REMOVE_CHILDREN](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-remove-children)

[MMCN_RENAME](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-rename)

### `arg` [in]

Depends on the notification type.

### `param` [in]

Depends on the notification type.

## Return value

This method can return one of these values.

## Remarks

For more information, see the individual notifications. The snap-in should return **S_FALSE** for any notification it does not handle.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)