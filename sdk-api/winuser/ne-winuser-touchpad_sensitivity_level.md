# TOUCHPAD_SENSITIVITY_LEVEL enumeration

## Description

Identifies values for the touchpad sensitivity setting.

## Constants

### `TOUCHPAD_SENSITIVITY_LEVEL_MOST_SENSITIVE:0x00000000`

The touchpad does not suppress mouse input generation after keyboard activity.

### `TOUCHPAD_SENSITIVITY_LEVEL_HIGH_SENSITIVITY:0x00000001`

The touchpad applies less mouse input suppression after keyboard activity.

### `TOUCHPAD_SENSITIVITY_LEVEL_MEDIUM_SENSITIVITY:0x00000002`

The touchpad applies its default level of mouse input suppression after keyboard activity.

### `TOUCHPAD_SENSITIVITY_LEVEL_LOW_SENSITIVITY:0x00000003`

The touchpad applies more mouse input suppression after keyboard activity.

### `TOUCHPAD_SENSITIVITY_LEVEL_LEAST_SENSITIVE:0x00000004`

The touchpad applies its maximum amount of mouse input suppression after keyboard activity.

## Remarks

The touchpad sensitivity setting causes the touchpad to suppress generation of mouse input after the user has typed on their keyboard. A higher sensitivity means the touchpad is more sensitive to touchpad input and does not suppress mouse input generation as much after keyboard activity.

## See also