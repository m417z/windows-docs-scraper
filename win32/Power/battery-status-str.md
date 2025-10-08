# BATTERY\_STATUS structure

Contains the current state of the battery. This structure is used by the [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status) control code.

## Members

**PowerState**

The battery state. This member can be zero, one, or more of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| **BATTERY\_CHARGING**<br>0x00000004 | Indicates that the battery is currently charging.<br> |
| **BATTERY\_CRITICAL**<br>0x00000008 | Indicates that battery failure is imminent. See the Remarks section for more information.<br> |
| **BATTERY\_DISCHARGING**<br>0x00000002 | Indicates that the battery is currently discharging.<br> |
| **BATTERY\_POWER\_ON\_LINE**<br>0x00000001 | Indicates that the system has access to AC power, so no batteries are being discharged.<br> |

**Capacity**

The current battery capacity, in mWh (or relative). This value can be used to generate a "gas gauge" display by dividing it by **FullChargedCapacity** member of the [**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str) structure. If the capacity is unavailable, this member is BATTERY\_UNKNOWN\_CAPACITY.

**Voltage**

The current battery voltage across the battery terminals, in millivolts (mv). If the voltage is unavailable, this member is BATTERY\_UNKNOWN\_VOLTAGE.

**Rate**

The current rate of battery charge or discharge. This value will be in milliwatts unless the battery rate information is relative, in which case it will be in arbitrary units per hour. To determine if battery information is relative, examine the BATTERY\_CAPACITY\_RELATIVE flag in the **Capabilities** member of the [**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str) structure. A nonzero, positive rate indicates charging; a negative rate indicates discharging. Some batteries report only discharging rates. If the rate is unavailable, this member is BATTERY\_UNKNOWN\_RATE. If the state of the battery or power source changes, the rate may become available.

## Remarks

The BATTERY\_CRITICAL flag in the **PowerState** member of this structure indicates a hardware "battery critical" condition. This critical level is set by the battery manufacturer, not by the user in the "critical battery alarm." It generally means that the battery system has calculated that the battery is totally drained, and any power being drawn is beyond what is expected.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h; <br>Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP |

## See also

[**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str)

[**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status)

