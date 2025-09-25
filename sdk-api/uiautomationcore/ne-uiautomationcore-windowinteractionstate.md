# WindowInteractionState enumeration

## Description

Contains values that specify the current state of the window for purposes of user interaction.

## Constants

### `WindowInteractionState_Running:0`

The window is running. This does not guarantee that the window is ready for user interaction or is responding.

### `WindowInteractionState_Closing:1`

The window is closing.

### `WindowInteractionState_ReadyForUserInteraction:2`

The window is ready for user interaction.

### `WindowInteractionState_BlockedByModalWindow:3`

The window is blocked by a modal window.

### `WindowInteractionState_NotResponding:4`

The window is not responding.

## See also

[IWindowProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iwindowprovider)