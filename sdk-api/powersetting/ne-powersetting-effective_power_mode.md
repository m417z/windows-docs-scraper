# EFFECTIVE_POWER_MODE enumeration

## Description

Indicates the effective power mode the system is running.

## Constants

### `EffectivePowerModeBatterySaver`

The system is in battery saver mode.

### `EffectivePowerModeEnergySaverHighSavings`

The system is in energy saver high savings mode. Save energy where possible.

This is an alias of the **EffectivePowerModeBatterySaver** mode.

> [!IMPORTANT]
> This information relates to a prerelease product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.

### `EffectivePowerModeBetterBattery`

The system is in the better battery effective power mode.

**Note** For systems using the legacy high performance overlay, this effective power mode will never be used.

### `EffectivePowerModeEnergySaverStandard`

The system is in energy saver standard mode. Save energy if the user experience impact is minimal.

This is an alias of the **EffectivePowerModeBetterBattery** mode.

> [!IMPORTANT]
> This information relates to a prerelease product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.

### `EffectivePowerModeBalanced`

The system is in the balanced effective power mode.

### `EffectivePowerModeHighPerformance`

The system is in the high performance effective power mode.

**Note** This effective power mode is only used for systems using the legacy high performance overlay.

### `EffectivePowerModeMaxPerformance`

The system is in the maximum performance effective power mode.

### `EffectivePowerModeGameMode`

The system is in game mode power mode.

**Note** This mode is only available with the EFFECTIVE_POWER_MODE_V2 version of the API

### `EffectivePowerModeMixedReality`

The system is in the windows mixed reality power mode.

**Note** This mode is only available with the EFFECTIVE_POWER_MODE_V2 version of the API