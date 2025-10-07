# SYSTEM\_EVENT\_DATA structure

Contains information about a tablet system event.

## Members

**bModifier**

Bit values for the modifiers. See the remarks section for more information.

**wKey**

Scan code for the keyboard character.

**xPos**

X position of the event.

**yPos**

Y position of the event.

**bCursorMode**

The type of cursor that caused the event. See the remarks section for more information.

**dwButtonState**

State of the buttons at the time of the system event.

## Remarks

The following system events are defined for use in the **bModifier** member.

| Value | Description |
|---------------------|------------------------------|
| SE\_MODIFIER\_CTRL | The Control key was pressed. |
| SE\_MODIFIER\_ALT | The Alt key was pressed. |
| SE\_MODIFIER\_SHIFT | The Shift key was pressed. |

The following system events are defined for use in the **bCursorMode** member.

| Value | Description |
|--------------------|---------------------------|
| SE\_NORMAL\_CURSOR | Indicates the pen tip. |
| SE\_ERASER\_CURSOR | Indicates the pen eraser. |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |

## See also

[**IStylusPlugin::SystemEvent Method**](https://learn.microsoft.com/windows/desktop/api/RTSCom/nf-rtscom-istylusplugin-systemevent)

[**ITabletEventSink::SystemEvent Method**](https://learn.microsoft.com/windows/win32/tablet/itableteventsink-systemevent)

