# MMC_ACTION_TYPE enumeration

## Description

The
MMC_ACTION_TYPE enumeration is introduced in MMC 1.1.

The
MMC_ACTION_TYPE enumeration defines the types of action that can be triggered when a user clicks a task on a taskpad. These values are used in the eActionType member of the
[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task) structure, which is filled in by the
[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) method.

## Constants

### `MMC_ACTION_UNINITIALIZED:-1`

No actions specified.

### `MMC_ACTION_ID`

When the user clicks the task, MMC calls
[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) and returns the command ID specified in the nCommandID member of the
MMC_TASK structure that was filled in when MMC called [IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) to add the task to the taskpad.

### `MMC_ACTION_LINK`

When the user clicks the task, MMC activates the link specified by the szActionURL member of the
MMC_TASK structure.

### `MMC_ACTION_SCRIPT`

When the user clicks the task, MMC executes the script contained in the szScript member of
MMC_TASK using the window.execScript method on the taskpad DHTML page.