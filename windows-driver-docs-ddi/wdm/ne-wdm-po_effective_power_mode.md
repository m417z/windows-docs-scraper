## Description

The **PO_EFFECTIVE_POWER_MODE** enumeration constants indicates the effective power mode the system is running.

## Constants

### `PoEffectivePowerModeBatterySaver`

The system is in battery saver effective power mode.

### `PoEffectivePowerModeEnergySaverHighSavings`

The system is in energy saver high savings effective power mode.

### `PoEffectivePowerModeBetterBattery`

The system is in better battery effective power mode. For systems using the legacy high performance overlay, this effective power mode will never be used.

### `PoEffectivePowerModeEnergySaverStandard`

The system is in the energy saver standard effective power mode.

### `PoEffectivePowerModeBalanced`

The system is in the balanced effective power mode.

### `PoEffectivePowerModeHighPerformance`

The system is in the high performance effective power mode. This power mode is only used for systems using the legacy high performance overlay.

### `PoEffectivePowerModeMaxPerformance`

The system is in the maximum performance effective power mode.

### `PoEffectivePowerModeGameMode`

The system is in game mode effective power mode.

### `PoEffectivePowerModeMixedReality`

The system is in the Windows Mixed Reality effective power mode.

## Remarks

## See also

[PO_EFFECTIVE_POWER_MODE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_effective_power_mode_callback)

[PoRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterforeffectivepowermodenotifications)

[PoUnregisterFromEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pounregisterfromeffectivepowermodenotifications)