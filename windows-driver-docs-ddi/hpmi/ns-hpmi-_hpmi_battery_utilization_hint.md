# _HPMI_BATTERY_UTILIZATION_HINT structure

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

This hint indicates if the OEM Battery Manager should attempt to save as much charge as possible in the non-hot swappable batteries (i.e. the batteries are generally referred to as "internal batteries", these batteries cannot be removed while system is operational).

## Members

### `Version`

Set to HPMI_BATTERY_UTILIZATION_HINT_VERSION_1.

### `PreserveNonHotSwappableBatteries`

 Interpretation of values:

- HpmiBoolUnavailable: Battery utilization hint is unavailable at the moment.

- HpmiBoolFalse: It is not necessary to preserve charge in the internal batteries at the moment.

- HpmiBoolTrue: Every attempt should be made to save as much charge as possible in the internal batteries.

## See also

[HPMI_HINT_BOOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ne-hpmi-_hpmi_hint_bool)

[IOCTL_HPMI_BATTERY_UTILIZATION_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ni-hpmi-ioctl_hpmi_battery_utilization_hint)

[hpmi.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/)