# BatteryClassUpdateData function

## Description

**BatteryClassUpdateData** notifies the battery class driver of changes in battery data.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle previously returned by [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

### `MiniportUpdateData` [in]

Pointer to [BATTERY_MINIPORT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_update_data) structure.

## Return value

**BatteryClassUpdateData** returns STATUS_SUCCESS.

## Remarks

This should be called at passive level.

Battery miniclass drivers must call **BatteryClassUpdateData** whenever any of the following occur:

* The battery charge limit changes.
* The battery's charging status changes, i.e No Power Supply, Inadequate Power Supply or Adequate Power Supply. This is used for barrel charger low wattge indicator.

## See also

[BATTERY_MINIPORT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_update_data)