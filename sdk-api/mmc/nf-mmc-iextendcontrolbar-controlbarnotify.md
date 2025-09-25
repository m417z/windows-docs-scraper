# IExtendControlbar::ControlbarNotify

## Description

The **IExtendControlbar::ControlbarNotify** method specifies the notification sent to the snap-in from the console as a result of user action.

## Parameters

### `event` [in]

A value that specifies one of the following:

#### MMCN_BTN_CLICK

A button on the toolbar was clicked.

#### MMCN_DESELECT_ALL

All items of a virtual list are deselected.

#### MMCN_SELECT

An item was selected and the snap-in should update the toolbar options.

#### MMCN_MENU_BTNCLICK

A menu button on the toolbar is clicked.

### `arg` [in]

Depends on the event parameter. For more information, see
[MMC Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-notifications).

### `param` [in]

Depends on the event parameter. For more information, see
[MMC Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-notifications).

## Return value

This method can return one of these values.

## Remarks

For more information, see the individual notifications. The snap-in should return S_FALSE for any notification it does not handle.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)