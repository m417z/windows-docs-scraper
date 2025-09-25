# SYSTEM_POWER_STATUS structure

## Description

Contains information about the power status of the system.

## Members

### `ACLineStatus`

The AC power status. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Offline |
| 1 | Online |
| 255 | Unknown status |

### `BatteryFlag`

The battery charge status. This member can contain one or more of the following flags.

| Value | Meaning |
| --- | --- |
| 1 | High—the battery capacity is at more than 66 percent |
| 2 | Low—the battery capacity is at less than 33 percent |
| 4 | Critical—the battery capacity is at less than five percent |
| 8 | Charging |
| 128 | No system battery |
| 255 | Unknown status—unable to read the battery flag information |

The value is zero if the battery is not being charged and the battery capacity is between low and high.

### `BatteryLifePercent`

The percentage of full battery charge remaining. This member can be a value in the range 0 to 100, or 255 if status is unknown.

### `SystemStatusFlag`

The status of battery saver. To participate in energy conservation, avoid resource intensive tasks when battery saver is on. To be notified when this value changes, call the [RegisterPowerSettingNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpowersettingnotification) function with the [power setting GUID](https://learn.microsoft.com/windows/desktop/Power/power-setting-guids), **GUID_POWER_SAVING_STATUS**.

| Value | Meaning |
| --- | --- |
| 0 | Battery saver is off. |
| 1 | Battery saver on. Save energy where possible. |

**Note** This flag and the **GUID_POWER_SAVING_STATUS** GUID were introduced in Windows 10. This flag was previously reserved, named **Reserved1**, and had a value of 0.

For general information about battery saver, see [battery saver (in the hardware component guidelines)](https://learn.microsoft.com/windows-hardware/design/component-guidelines/battery-saver).

### `BatteryLifeTime`

The number of seconds of battery life remaining, or –1 if remaining seconds are unknown or if the device is connected to AC power.

### `BatteryFullLifeTime`

The number of seconds of battery life when at full charge, or –1 if full battery lifetime is unknown or if the device is connected to AC power.

## Remarks

The system is only capable of estimating **BatteryFullLifeTime** based on calculations on **BatteryLifeTime** and **BatteryLifePercent**. Without smart battery subsystems, this value may not be accurate enough to be useful.

## See also

[GetSystemPowerStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystempowerstatus)

[PBT_APMPOWERSTATUSCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-apmpowerstatuschange)

[battery saver (in the hardware component guidelines)](https://learn.microsoft.com/windows-hardware/design/component-guidelines/battery-saver)