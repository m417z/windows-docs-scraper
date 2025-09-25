# PEDOMETER_STEP_TYPE enumeration

## Description

This enumeration represents the step types reported by the pedometer.

## Constants

### `PedometerStepType_Unknown`

The pedometer cannot determine the step type.

### `PedometerStepType_Walking`

Indicates a step type associated with walking.

### `PedometerStepType_Running`

Indicates a step type associated with running.

### `PedometerStepType_Max`

Indicates that the step type is generating maximum sensor values. In this scenario, the pedometer doesn't report the step type.

### `PedometerStepType_Force_Dword`

Used to force the PEDOMETER_STEP_TYPE enum to a 32-bit data type (a DWORD).

## Remarks

For more information about the sensor data fields that use this enumeration, see [Pedometer data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/pedometer-data-fields).

## See also

[PEDOMETER_STEP_TYPE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ne-sensorsdef-pedometer_step_type_count)

[Pedometer data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/pedometer-data-fields)