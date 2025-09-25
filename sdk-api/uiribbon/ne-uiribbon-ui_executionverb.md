# UI_EXECUTIONVERB enumeration

## Description

Specifies values that identify the execution IDs that map to actions a user can initiate on a [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command).

## Constants

### `UI_EXECUTIONVERB_EXECUTE:0`

Execute a command.

### `UI_EXECUTIONVERB_PREVIEW:1`

Show a preview of a visual element.

### `UI_EXECUTIONVERB_CANCELPREVIEW:2`

Cancel a preview of a visual element.

## Remarks

In the Ribbon framework, user actions are called executions.

For example, if a user hovers the mouse over a gallery item, UI_EXECUTIONVERB_PREVIEW is passed in a call to the [IUICommandHandler::Execute](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuicommandhandler-execute) function of the gallery to indicate that a live preview event occurred on the item. If the user clicks the gallery item, UI_EXECUTIONVERB_EXECUTE is passed in a subsequent call to the **IUICommandHandler::Execute** function to indicate that the item was executed.

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[Understanding Commands and Controls](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-commandscontrols)

[Working with Galleries](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-controls-galleries)