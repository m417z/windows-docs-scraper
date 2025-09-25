# PWM_CONTROLLER_SET_DESIRED_PERIOD_INPUT structure

## Description

Contains an input value for a suggested signal period for the Pulse Width Modulation (PWM) controller.

## Members

### `DesiredPeriod`

The desired output signal period, in picoseconds, for the controller. This value must be greater than zero (0). It must be in the controller supported range of periods, which is between the **MinimumPeriod** and **MaximumPeriod** values, inclusive, which you can obtain by using [IOCTL_PWM_CONTROLLER_GET_INFO](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_controller_get_info). If the value is not valid, the request is completed with a STATUS_INVALID_PARAMETER value.

## See also

[IOCTL_PWM_CONTROLLER_GET_ACTUAL_PERIOD](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_controller_get_actual_period)

[IOCTL_PWM_CONTROLLER_GET_INFO](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_controller_get_info)

[IOCTL_PWM_CONTROLLER_SET_DESIRED_PERIOD](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_controller_set_desired_period)