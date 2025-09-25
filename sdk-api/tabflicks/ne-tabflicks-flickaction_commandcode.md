# FLICKACTION_COMMANDCODE enumeration

## Description

Defines the possible flick actions that can be assigned to a pen flick.

## Constants

### `FLICKACTION_COMMANDCODE_NULL:0`

No action is assigned to the pen flick.

### `FLICKACTION_COMMANDCODE_SCROLL:1`

A scrolling command is assigned to the pen flick.

### `FLICKACTION_COMMANDCODE_APPCOMMAND:2`

An application command is assigned to a pen flick.

### `FLICKACTION_COMMANDCODE_CUSTOMKEY:3`

A customized key sequence is assigned to the pen flick.

### `FLICKACTION_COMMANDCODE_KEYMODIFIER:4`

A key modifier is assigned to the pen flick.

## Remarks

In Control Panel, the user can assign commands to pen flicks. Four types of actions with pen flicks include:

* Scroll Up or Scroll Down.
* An application command such as Back or Undo
* Any keystroke or keystroke combination such as CONTROL+N.
* Activating a modifier key such as SHIFT

## See also

[flick_data structure](https://learn.microsoft.com/windows/desktop/api/tabflicks/ns-tabflicks-flick_data)

[flicks gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures)

[responding to pen flicks](https://learn.microsoft.com/previous-versions/windows/desktop/ms703447(v=vs.85))

[wm_tablet_flick message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message)