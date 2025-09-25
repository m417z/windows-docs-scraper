## Description

The **KSPROPERTY_TUNER_STATUS_S** structure describes the progress of a tuning operation for TV and radio tuner devices, including present tuning frequency.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `CurrentFrequency`

Specifies the current tuner frequency. This value is in hertz (Hz).

### `PLLOffset`

Specifies the phase locked loop (PLL) offset in multiples of the tuning granularity. This is used if the tuner strategy is KS_TUNER_STRATEGY_PLL. If the tuner strategy is not KS_TUNER_STRATEGY_PLL, this value has no meaning. The following table demonstrates the value to be returned by the minidriver for various tuning conditions, assuming the tuning granularity is 62.5kHz:

| Frequency Offset | PLLOffset |
|---|---|
| +125,000 | +2 |
| +62,500 | +1 |
| Perfectly tuned | 0 |
| -62,500 | -1 |
| -125,000 | -2 |

### `SignalStrength`

Specifies the amplitude of the signal. This is used if the tuner strategy is KS_TUNER_STRATEGY_SIGNAL_STRENGTH. Regardless of the tuning strategy supported by the minidriver, the valid values for this member are:

| Value | Meaning |
|---|---|
| -1 | Strength not Available. |
| 0 | Not on an acceptable frequency. |
| 1 | On an acceptable frequency. |

### `Busy`

Indicates if the minidriver is presently busy with the process of tuning. This member must be set to **TRUE** if the minidriver is currently tuning to a channel. Otherwise, if the minidriver is not currently tuning to a new channel, this member must be set to **FALSE**.

## Remarks

For more information about the **PLLOffset** and **SignalStrength** members see [PCI based TV capture](https://learn.microsoft.com/windows-hardware/drivers/stream/pci-based-tv-capture). If your tuner device supports radio tuning, see [Video Capture Devices with Radio Tuners](https://learn.microsoft.com/windows-hardware/drivers/stream/video-capture-devices-with-radio-tuners).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_STATUS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-status)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)