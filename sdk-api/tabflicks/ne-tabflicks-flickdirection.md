# FLICKDIRECTION enumeration

## Description

Defines the directions in which a pen flick has occurred.

## Constants

### `FLICKDIRECTION_MIN:0`

### `FLICKDIRECTION_RIGHT:0`

 A pen flick to the right.

### `FLICKDIRECTION_UPRIGHT:1`

 A pen flick to the upper right.

### `FLICKDIRECTION_UP:2`

 An upward pen flick.

### `FLICKDIRECTION_UPLEFT:3`

A pen flick to the upper left.

### `FLICKDIRECTION_LEFT:4`

A pen flick to the left.

### `FLICKDIRECTION_DOWNLEFT:5`

A pen flick to the lower left.

### `FLICKDIRECTION_DOWN:6`

A downward pen flick.

### `FLICKDIRECTION_DOWNRIGHT:7`

A pen flick to the down right.

### `FLICKDIRECTION_INVALID:8`

An invalid pen flick.

## Remarks

A pen flick is a unidirectional pen gesture that requires the user to contact the digitizer in a quick, straight flicking motion. A flick is characterized by high speed and a high degree of straightness. A flick is identified by its direction. Flicks can be made in eight directions corresponding to the cardinal and secondary compass directions.

## See also

[FLICK_DATA Structure](https://learn.microsoft.com/windows/desktop/api/tabflicks/ns-tabflicks-flick_data)

[Flicks Gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures)

[Responding to Pen Flicks](https://learn.microsoft.com/previous-versions/windows/desktop/ms703447(v=vs.85))

[WM_TABLET_FLICK Message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message)