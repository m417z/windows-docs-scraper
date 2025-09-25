# JOYINFOEX structure

## Description

The **JOYINFOEX** structure contains extended information about the joystick position, point-of-view position, and button state.

## Members

### `dwSize`

Size, in bytes, of this structure.

### `dwFlags`

Flags indicating the valid information returned in this structure. Members that do not contain valid information are set to zero. The following flags are defined:

| Flag | Description |
| --- | --- |
| JOY_RETURNALL | Equivalent to setting all of the JOY_RETURN bits except JOY_RETURNRAWDATA. |
| JOY_RETURNBUTTONS | The **dwButtons** member contains valid information about the state of each joystick button. |
| JOY_RETURNCENTERED | Centers the joystick neutral position to the middle value of each axis of movement. |
| JOY_RETURNPOV | The **dwPOV** member contains valid information about the point-of-view control, expressed in discrete units. |
| JOY_RETURNPOVCTS | The **dwPOV** member contains valid information about the point-of-view control expressed in continuous, one-hundredth degree units. |
| JOY_RETURNR | The **dwRpos** member contains valid rudder pedal data. This information represents another (fourth) axis. |
| JOY_RETURNRAWDATA | Data stored in this structure is uncalibrated joystick readings. |
| JOY_RETURNU | The **dwUpos** member contains valid data for a fifth axis of the joystick, if such an axis is available, or returns zero otherwise. |
| JOY_RETURNV | The **dwVpos** member contains valid data for a sixth axis of the joystick, if such an axis is available, or returns zero otherwise. |
| JOY_RETURNX | The **dwXpos** member contains valid data for the x-coordinate of the joystick. |
| JOY_RETURNY | The **dwYpos** member contains valid data for the y-coordinate of the joystick. |
| JOY_RETURNZ | The **dwZpos** member contains valid data for the z-coordinate of the joystick. |

The following flags provide data to calibrate a joystick and are intended for custom calibration applications.

| Flag | Description |
| --- | --- |
| JOY_CAL_READ3 | Read the x-, y-, and z-coordinates and store the raw values in **dwXpos**, **dwYpos**, and **dwZpos**. |
| JOY_CAL_READ4 | Read the rudder information and the x-, y-, and z-coordinates and store the raw values in **dwXpos**, **dwYpos**, **dwZpos**, and **dwRpos**. |
| JOY_CAL_READ5 | Read the rudder information and the x-, y-, z-, and u-coordinates and store the raw values in **dwXpos**, **dwYpos**, **dwZpos**, **dwRpos**, and **dwUpos**. |
| JOY_CAL_READ6 | Read the raw v-axis data if a joystick mini driver is present that will provide the data. Returns zero otherwise. |
| JOY_CAL_READALWAYS | Read the joystick port even if the driver does not detect a device. |
| JOY_CAL_READRONLY | Read the rudder information if a joystick mini-driver is present that will provide the data and store the raw value in **dwRpos**. Return zero otherwise. |
| JOY_CAL_READXONLY | Read the x-coordinate and store the raw (uncalibrated) value in **dwXpos**. |
| JOY_CAL_READXYONLY | Reads the x- and y-coordinates and place the raw values in **dwXpos** and **dwYpos**. |
| JOY_CAL_READYONLY | Reads the y-coordinate and store the raw value in **dwYpos**. |
| JOY_CAL_READZONLY | Read the z-coordinate and store the raw value in **dwZpos**. |
| JOY_CAL_READUONLY | Read the u-coordinate if a joystick mini-driver is present that will provide the data and store the raw value in **dwUpos**. Return zero otherwise. |
| JOY_CAL_READVONLY | Read the v-coordinate if a joystick mini-driver is present that will provide the data and store the raw value in **dwVpos**. Return zero otherwise. |

### `dwXpos`

Current X-coordinate.

### `dwYpos`

Current Y-coordinate.

### `dwZpos`

Current Z-coordinate.

### `dwRpos`

Current position of the rudder or fourth joystick axis.

### `dwUpos`

Current fifth axis position.

### `dwVpos`

Current sixth axis position.

### `dwButtons`

Current state of the 32 joystick buttons. The value of this member can be set to any combination of JOY_BUTTON *n* flags, where *n* is a value in the range of 1 through 32 corresponding to the button that is pressed.

### `dwButtonNumber`

Current button number that is pressed.

### `dwPOV`

Current position of the point-of-view control. Values for this member are in the range 0 through 35,900. These values represent the angle, in degrees, of each view multiplied by 100.

### `dwReserved1`

Reserved; do not use.

### `dwReserved2`

Reserved; do not use.

## Remarks

The value of the **dwSize** member is also used to identify the version number for the structure when it's passed to the [joyGetPosEx](https://learn.microsoft.com/previous-versions/dd757108(v=vs.85)) function.

Most devices with a point-of-view control have only five positions. When the JOY_RETURNPOV flag is set, these positions are reported by using the following constants:

| Point-Of-View Flag | Description |
| --- | --- |
| JOY_POVBACKWARD | Point-of-view hat is pressed backward. The value 18,000 represents an orientation of 180.00 degrees (to the rear). |
| JOY_POVCENTERED | Point-of-view hat is in the neutral position. The value -1 means the point-of-view hat has no angle to report. |
| JOY_POVFORWARD | Point-of-view hat is pressed forward. The value 0 represents an orientation of 0.00 degrees (straight ahead). |
| JOY_POVLEFT | Point-of-view hat is being pressed to the left. The value 27,000 represents an orientation of 270.00 degrees (90.00 degrees to the left). |
| JOY_POVRIGHT | Point-of-view hat is pressed to the right. The value 9,000 represents an orientation of 90.00 degrees (to the right). |

The default joystick driver currently supports these five discrete directions. If an application can accept only the defined point-of-view values, it must use the JOY_RETURNPOV flag. If an application can accept other degree readings, it should use the JOY_RETURNPOVCTS flag to obtain continuous data if it is available. The JOY_RETURNPOVCTS flag also supports the JOY_POV constants used with the JOY_RETURNPOV flag.

## See also

Joysticks

Multimedia Joystick Structures

[joyGetPosEx](https://learn.microsoft.com/previous-versions/dd757108(v=vs.85))