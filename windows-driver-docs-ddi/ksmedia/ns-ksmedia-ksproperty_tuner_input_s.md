# KSPROPERTY_TUNER_INPUT_S structure

## Description

The KSPROPERTY_TUNER_INPUT_S structure describes the input connection index of a tuner device for devices that support multiple inputs.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `InputIndex`

Specifies the connection index to be used as the tuner input. This value should be in the range of 0 through (number of inputs-1).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_INPUT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-input)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)