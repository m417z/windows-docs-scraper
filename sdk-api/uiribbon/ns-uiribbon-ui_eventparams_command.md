# UI_EVENTPARAMS_COMMAND structure

## Description

Contains information about a [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) associated with a event.

## Members

### `CommandID`

The ID of the [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) directly related to the event, which is specified in the markup resource file.

### `CommandName`

The [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) name that is associated with **CommandId**.

### `ParentCommandID`

The ID for the parent of the [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command), which is specified in the markup resource file.

### `ParentCommandName`

The [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) name of the parent that is associated with **CommandId**.

### `SelectionIndex`

**SelectionIndex** is used only when a [UI_EVENTTYPE_CommandExecuted](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventtype) has been fired in response to the user selecting an item within a [ComboBox](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-combobox) or item gallery. In those cases, **SelectionIndex** contains the index of the selected item. In all other cases, it is set to 0.

### `Location`

One of the values from [UI_EVENTLOCATION](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventlocation).

## Remarks

 The Command identified by **CommandID** and **CommandName** depend upon which event has occurred: for a [UI_EVENTTYPE_TabActivated](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventtype) event, they identify the tab; for a **UI_EVENTTYPE_MenuOpened** event, they identify the menu; for **UI_EVENTTYPE_CommandExecuted** events, they identify the command being executed; and for **UI_EVENTTYPE_TooltipShown** events, they identify the [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) that owns that tooltip.

**ParentCommandID** and **ParentCommandName** identify the parent command (if any) of the command associated with this event. If there is no parent, then **ParentCommandID** is zero and **ParentCommandName** is an empty string.

## See also

[OnUIEvent](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuieventlogger-onuievent)

[Structures](https://learn.microsoft.com/windows/desktop/windowsribbon/structures)

[UI_EVENTPARAMS](https://learn.microsoft.com/windows/desktop/api/uiribbon/ns-uiribbon-ui_eventparams)