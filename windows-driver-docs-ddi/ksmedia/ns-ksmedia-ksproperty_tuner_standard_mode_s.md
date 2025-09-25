# KSPROPERTY_TUNER_STANDARD_MODE_S structure

## Description

The KSPROPERTY_TUNER_STANDARD_MODE_S structure describes whether the tuning device can identify the tuner standard from the signal itself.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `AutoDetect`

A Boolean value that indicates whether the tuning device can automatically detect the tuner standard from the signal. **TRUE** indicates that the tuning device can automatically detect the tuner standard from the signal. **FALSE** indicates that the tuning device cannot automatically detect the tuner standard.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_STANDARD_MODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-standard-mode)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)