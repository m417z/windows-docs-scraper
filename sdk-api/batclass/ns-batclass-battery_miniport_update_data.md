# BATTERY_MINIPORT_UPDATE_DATA structure

## Description

Battery miniclass drivers fill in this structure before calling the battery class driver's [BatteryClassUpdateData](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassUpdatedata) routine.

## Members

### `Version`

Specifies the version number of the structure. Miniclass drivers should specify BATTERY_MINIPORT_UPDATE_DATA_VER_2.

### `NotifyEvent`

Specifies the information as specified in the [BATTERY_NON_CATASTROPHIC_EVENT](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_non_catastrophic_event) struct

## See also

[BatteryClassUpdateData](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassUpdatedata).