# SYSTEM_EVENT_DATA structure

## Description

Contains information about a tablet system event.

## Members

### `bModifier`

Bit values for the modifiers. Possible values include SE_MODIFIER_CTRL (the Control key was pressed), SE_MODIFIER_ALT (the Alt key was pressed), and SE_MODIFIER_SHIFT (the Shift key was pressed).

### `wKey`

Scan code for the keyboard character.

### `xPos`

X position of the event.

### `yPos`

Y position of the event.

### `bCursorMode`

The type of cursor that caused the event. Possible values include SE_NORMAL_CURSOR (the pen tip) and SE_ERASER_CURSOR (the eraser).

### `dwButtonState`

State of the buttons at the time of the system event.

## See also

[IStylusPlugin::SystemEvent Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-systemevent)

[ITabletEventSink::SystemEvent Method](https://learn.microsoft.com/windows/desktop/tablet/itableteventsink-systemevent)