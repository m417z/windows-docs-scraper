# MMC_RESTORE_VIEW structure

## Description

The
MMC_RESTORE_VIEW structure is introduced in MMC 1.1.

The
MMC_RESTORE_VIEW structure contains information about a result pane view that must be restored by the snap-in when the user has navigated to a view displayed in the view history using the back or forward buttons.

## Members

### `dwSize`

A value that specifies the size of the
MMC_RESTORE_VIEW structure. A snap-in can use dwSize to check the version of the structure.

### `cookie`

A value that specifies the cookie for the item that will be restored in the scope pane.

### `pViewType`

A pointer to a string that specifies the view type used to display the result pane for the item specified by cookie. For more information about view types, see the ppViewType parameter for
[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype).

### `lViewOptions`

A value that specifies the view option settings used to display the result pane for the item specified by cookie. For more information about view options, see the pViewOptions parameter of [IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype).

## Remarks

MMC maintains a navigational history of the result pane. For each item in the history, MMC stores the view type and view options specified by [IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) when the result pane was originally displayed during the course of the current console session. When the back or forward buttons are used to navigate the history, MMC sends the snap-in that owns that item an
[MMCN_RESTORE_VIEW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-restore-view) notification that has a pointer to an
MMC_RESTORE_VIEW structure as its arg parameter and a pointer to a BOOL as its param parameter. The snap-in should handle that notification by setting the appropriate menu item in the
**View** context menu, setting its internal view type state, and performing any initialization necessary to display the result pane as it appeared at that point in the view history.

## See also

[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype)

[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify)

[MMCN_RESTORE_VIEW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-restore-view)