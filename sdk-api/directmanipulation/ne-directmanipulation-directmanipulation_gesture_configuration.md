# DIRECTMANIPULATION_GESTURE_CONFIGURATION enumeration

## Description

Defines the gestures that can be passed to [SetManualGesture](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setmanualgesture).

## Constants

### `DIRECTMANIPULATION_GESTURE_NONE:0`

No gestures are defined.

### `DIRECTMANIPULATION_GESTURE_DEFAULT:0`

Only default gestures are supported. This is the default value.

### `DIRECTMANIPULATION_GESTURE_CROSS_SLIDE_VERTICAL:0x8`

Vertical slide and swipe gestures are supported through the cross-slide interaction. For more information, see [Guidelines for cross-slide](https://learn.microsoft.com/windows/uwp/input-and-devices/guidelines-for-cross-slide).

### `DIRECTMANIPULATION_GESTURE_CROSS_SLIDE_HORIZONTAL:0x10`

Horizontal slide and swipe gestures are supported through the cross-slide interaction. For more information, see [Guidelines for cross-slide](https://learn.microsoft.com/windows/uwp/input-and-devices/guidelines-for-cross-slide).

### `DIRECTMANIPULATION_GESTURE_PINCH_ZOOM:0x20`

Pinch and stretch gestures for zooming.

## Remarks

By default, [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) always reassigns tap and press-and-hold gestures to the application.

Use **DIRECTMANIPULATION_GESTURE_PINCH_ZOOM** to zoom instead of scale.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)