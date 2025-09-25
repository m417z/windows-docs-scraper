# KS_TUNER_STRATEGY enumeration

## Description

The KS_TUNER_STRATEGY enumeration defines tuning method strategies.

## Constants

### `KS_TUNER_STRATEGY_PLL`

The tuning accuracy for the device is measured by a phase locked loop (PLL) offset.

### `KS_TUNER_STRATEGY_SIGNAL_STRENGTH`

The tuning accuracy for the device is measured by signal strength.

### `KS_TUNER_STRATEGY_DRIVER_TUNES`

The minidriver has total control over the fine tuning process. No fine tuning is done by *Kstvtune.ax*.

## See also

[KSPROPERTY_TUNER_MODE_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_tuner_mode_caps_s)