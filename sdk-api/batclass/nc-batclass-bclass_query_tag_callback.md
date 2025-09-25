# BCLASS_QUERY_TAG_CALLBACK callback function

## Description

*BatteryMiniQueryTag* returns the current battery tag.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

### `BatteryTag` [out]

A pointer to a caller-allocated variable in which the miniclass driver returns the battery tag.

## Return value

*BatteryMiniQueryTag* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A battery is currently installed. |
| **STATUS_NO_SUCH_DEVICE** | No battery is present. |

## Remarks

The battery class driver calls *BatteryMiniQueryTag* to get the value of the current battery tag. If a battery is present, *BatteryMiniQueryTag* should return the tag in *BatteryTag* and return STATUS_SUCCESS.

Each time a battery is inserted, the miniclass driver must increment the value of the tag, regardless of whether this is a new battery or the same battery that was previously present.

If no battery is present, or if the miniclass driver cannot determine whether a battery is present, it should return STATUS_NO_SUCH_DEVICE and set the value of the tag to BATTERY_TAG_INVALID.