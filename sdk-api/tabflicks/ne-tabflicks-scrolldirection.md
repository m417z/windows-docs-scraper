# SCROLLDIRECTION enumeration

## Description

Defines the direction of the scrolling command for a pen flick.

## Constants

### `SCROLLDIRECTION_UP:0`

 The flick action is a Scroll Up command.

### `SCROLLDIRECTION_DOWN:1`

The flick action is a Scroll Down command.

## Remarks

When the user performs a pen flick that is assigned to a scrolling command, the [WM_TABLET_FLICK Message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message) sends the direction of the scrolling command as part of the [FLICK_DATA Structure](https://learn.microsoft.com/windows/desktop/api/tabflicks/ns-tabflicks-flick_data).

## See also

[flick_data structure](https://learn.microsoft.com/windows/desktop/api/tabflicks/ns-tabflicks-flick_data)

[flicks gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures)

[responding to pen flicks](https://learn.microsoft.com/previous-versions/windows/desktop/ms703447(v=vs.85))

[wm_tablet_flick message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message)