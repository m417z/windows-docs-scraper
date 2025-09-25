# BATTERY_NON_CATASTROPHIC_EVENT structure

## Description

A battery miniclass driver fill BATTERY_NON_CATASTROPHIC_EVENT structure when it notify class driver about battery data update [BatteryClassUpdateData](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassUpdatedata).

## Members

### `BatteryChargeLimitState`

This is one bit, when set miniport notifying the class driver that battery is charge limit state, flase otherwise.

### `BatteryChargingState`

This is 2 bit, miniport specify one of the enum value BatteryNoPowerSupply, BatteryInadequatePowerSupply or BatteryAdequatePowerSupply

### `Reserved`

Rest 29 bits are reserved and not-used..

## See also

[BatteryClassUpdateData](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassUpdatedata).