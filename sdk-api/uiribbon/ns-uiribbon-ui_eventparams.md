# UI_EVENTPARAMS structure

## Description

Contains information about a [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) event.

## Members

### `EventType`

One of the values from [UI_EVENTTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventtype).

### `Modes`

The application modes.

### `Params`

The [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) associated with the event.

## Remarks

For top-level events (application menu opened/closed, ribbon minimized/expanded/pinned), **Modes** is present but set to zero (and can be ignored by the application).

For the [UI_EVENTTYPE_ApplicationModeSwitched](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventtype) event, **Modes** specifies which modes have been set. (This is the same integer value that is passed to [SetModes](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-setmodes) to switch modes in the first place.)

For all other events, **Params** contains additional data about the event.

## See also

[OnUIEvent](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuieventlogger-onuievent)

[Reconfiguring the Ribbon with Application Modes](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-applicationmodes)

[SetModes](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-setmodes)

[Structures](https://learn.microsoft.com/windows/desktop/windowsribbon/structures)