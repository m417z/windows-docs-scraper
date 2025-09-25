# tagKSCAMERA_EXTENDEDPROP_EVCOMPENSATION structure

## Description

The *EV Compensation Control* provides for exposure control that is adjusted by increments of EV compensation steps.

## Members

### `Mode`

Not used. Set to 0.

### `Min`

The minimum EV compensation supported. This is an absolute EV value.

### `Max`

The maximum EV compensation supported. This is an absolute EV value.

### `Value`

EV Compensation in units of steps selected in the **Flags** member of [KSCAMERA_EXTENDEDPROP_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_extendedprop_header).

### `Reserved`

Reserved.

## Remarks

**Value** is assigned a stepping increment. For example, if **Min** = -2, **Max** = 2 and the compensation stepping is set as one third step (incremented in units of 1/3 EV compensation), the valid values of EV compensation are -2, -1 2/3, -1 1/3, -1, -2/3, -1/3, 0, 1/3, 2/3, 1, 1 1/3, 1 2/3, and 2. This corresponds to the **Value** field as -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6. As an example, if **Value** = -6, then EV compensation = -2, or (-6 * 1/3) = -2.

## See also

[KSCAMERA_EXTENDEDPROP_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_extendedprop_header)

[KSPROPERTY_CAMERACONTROL_EXTENDED_EVCOMPENSATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-evcompensation)