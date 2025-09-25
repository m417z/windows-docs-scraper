# UI_EVENTTYPE enumeration

## Description

Identifies the types of events associated with a [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon).

## Constants

### `UI_EVENTTYPE_ApplicationMenuOpened:0`

The [ApplicationMenu](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-applicationmenu) opened.

### `UI_EVENTTYPE_RibbonMinimized:1`

The [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) minimized.

### `UI_EVENTTYPE_RibbonExpanded:2`

The [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) expanded.

### `UI_EVENTTYPE_ApplicationModeSwitched:3`

The [application mode](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-applicationmodes) changed.

### `UI_EVENTTYPE_TabActivated:4`

A [Tab](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-tab) activated.

### `UI_EVENTTYPE_MenuOpened:5`

A menu opened.

### `UI_EVENTTYPE_CommandExecuted:6`

A [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) executed.

### `UI_EVENTTYPE_TooltipShown:7`

A [Command](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command) tooltip displayed.

## Remarks

**UI_EVENTTYPE_TabActivated** is fired for both core tabs and contextual tabs; the [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) event system does not distinguish between the two.

**UI_EVENTTYPE_MenuOpened** and **UI_EVENTTYPE_MenuClosed** are fired when either a regular menu or a gallery menu is opened or closed.

No event is fired when the [QuickAccessToolbar](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-quickaccesstoolbar) menu is opened or closed.

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[OnUIEvent](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuieventlogger-onuievent)

[UI_EVENTLOCATION](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_eventlocation)