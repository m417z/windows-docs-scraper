# KS_TUNER_TUNING_FLAGS enumeration

## Description

The KS_TUNER_TUNING_FLAGS enumeration defines tuning flags that describe the granularity of a tuning operation.

## Constants

### `KS_TUNER_TUNING_EXACT`

The tuner should tune directly to the specified frequency and bypass any fine tuning logic.

### `KS_TUNER_TUNING_FINE`

The tuning operation should perform a comprehensive search for the best tuning. This flag is used only if the strategy is KS_TUNER_STRATEGY_DRIVER_TUNES.

### `KS_TUNER_TUNING_COARSE`

The tuning operation should perform a fast search and attempt only to determine if a valid signal is present. This flag is used only if the strategy is KS_TUNER_STRATEGY_DRIVER_TUNES.

## See also

[KSPROPERTY_TUNER_FREQUENCY_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_tuner_frequency_s)