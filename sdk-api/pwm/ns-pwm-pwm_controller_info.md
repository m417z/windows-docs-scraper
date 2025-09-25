# PWM_CONTROLLER_INFO structure

## Description

Represents the static information that characterizes a Pulse Width Modulation (PWM) controller.

## Members

### `Size`

The size of the structure, which includes the **Size** member. The structure byte size is used for versioning.

### `PinCount`

The number of available pins or channels of the controller, which must be greater than zero (0).

### `MinimumPeriod`

The minimum supported output signal period, in picoseconds, for the controller. This value must be greater than zero and less than or equal the **MaximumPeriod** value.

### `MaximumPeriod`

The maximum supported output signal period, in picoseconds, for the controller. This value must be greater than zero and greater than or equal the **MinimumPeriod** value.

## See also

[IOCTL_PWM_CONTROLLER_GET_INFO](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_controller_get_info)