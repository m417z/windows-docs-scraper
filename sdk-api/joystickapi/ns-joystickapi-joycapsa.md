# JOYCAPSA structure

## Description

The **JOYCAPS** structure contains information about the joystick capabilities.

## Members

### `wMid`

Manufacturer identifier. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `szPname`

Null-terminated string containing the joystick product name.

### `wXmin`

Minimum X-coordinate.

### `wXmax`

Maximum X-coordinate.

### `wYmin`

Minimum Y-coordinate.

### `wYmax`

Maximum Y-coordinate.

### `wZmin`

Minimum Z-coordinate.

### `wZmax`

Maximum Z-coordinate.

### `wNumButtons`

Number of joystick buttons.

### `wPeriodMin`

Smallest polling frequency supported when captured by the [joySetCapture](https://learn.microsoft.com/previous-versions/dd757114(v=vs.85)) function.

### `wPeriodMax`

Largest polling frequency supported when captured by **joySetCapture**.

### `wRmin`

Minimum rudder value. The rudder is a fourth axis of movement.

### `wRmax`

Maximum rudder value. The rudder is a fourth axis of movement.

### `wUmin`

Minimum u-coordinate (fifth axis) values.

### `wUmax`

Maximum u-coordinate (fifth axis) values.

### `wVmin`

Minimum v-coordinate (sixth axis) values.

### `wVmax`

Maximum v-coordinate (sixth axis) values.

### `wCaps`

Joystick capabilities The following flags define individual capabilities that a joystick might have:

| Flag | Description |
| --- | --- |
| JOYCAPS_HASZ | Joystick has z-coordinate information. |
| JOYCAPS_HASR | Joystick has rudder (fourth axis) information. |
| JOYCAPS_HASU | Joystick has u-coordinate (fifth axis) information. |
| JOYCAPS_HASV | Joystick has v-coordinate (sixth axis) information. |
| JOYCAPS_HASPOV | Joystick has point-of-view information. |
| JOYCAPS_POV4DIR | Joystick point-of-view supports discrete values (centered, forward, backward, left, and right). |
| JOYCAPS_POVCTS | Joystick point-of-view supports continuous degree bearings. |

### `wMaxAxes`

Maximum number of axes supported by the joystick.

### `wNumAxes`

Number of axes currently in use by the joystick.

### `wMaxButtons`

Maximum number of buttons supported by the joystick.

### `szRegKey`

Null-terminated string containing the registry key for the joystick.

### `szOEMVxD`

Null-terminated string identifying the joystick driver OEM.

## See also

Joysticks

Multimedia Joystick Structures

[joySetCapture](https://learn.microsoft.com/previous-versions/dd757114(v=vs.85))

## Remarks

> [!NOTE]
> The joystickapi.h header defines JOYCAPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).