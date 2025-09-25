## Description

The **VIDEO_BRIGHTNESS_POLICY** structure is used for setting brightness policy through the [Device Power Policy Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-device-power-policy).

## Members

### `DefaultToBiosPolicy`

Boolean value that specifies whether the brightness values should be adjusted to reflect the suggestions made by the system BIOS.

### `LevelCount`

Number of brightness levels specified in the **Levels** array; that is, the number of **BatteryLevel** and **Brightness** pairs specified.

### `BatteryLevel`

Value that specifies the level below which the **Brightness** value applies.

### `Brightness`

Value that expresses the percentage of how bright the screen should be at or below the **BatteryLevel**.

### `Level[1]`

Array of **BatteryLevel** and **Brightness** pairs that specify the brightness levels.