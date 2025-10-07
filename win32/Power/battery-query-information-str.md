# BATTERY\_QUERY\_INFORMATION structure

Contains battery query information. This structure is used with the [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information) control code to specify the type of information to return.

## Members

**BatteryTag**

The current battery tag for the battery. Only information for a battery matching the tag can be returned. Whenever this value does not match the battery's current tag, the IOCTL request will be completed with ERROR\_FILE\_NOT\_FOUND. This indicates to the caller that the battery associated with the tag longer exists. The caller may opt to use the [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag) operation to determine the tag of the newly installed battery, if one exists. (See [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information.)

When a query information request is made, this value is verified. In addition, if the request is in progress while this value changes, the request is aborted with the status of ERROR\_FILE\_NOT\_FOUND.

**InformationLevel**

The level of the battery information being queried. The data returned by the IOCTL depends on this value. This member can be one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **BatteryDeviceName**

4 | Null-terminated Unicode string that contains the battery's name.\ | | **BatteryEstimatedTime**

3 | A **ULONG** that specifies the estimated battery run time, in seconds. If the rate of drain provided in the **AtRate** member of the **BATTERY\_QUERY\_INFORMATION** structure is zero, this calculation is based on the present rate of drain. If **AtRate** is nonzero, the time returned is the expected run time for the given rate. If the estimated time is unknown (for example, the battery is not discharging and the **AtRate** specified was zero), the return value is BATTERY\_UNKNOWN\_TIME. Note that this value is not very accurate on some battery systems, and may vary widely depending on present power usage, which could be affected by disk activity and other factors. There is no notification mechanism for changes in this value.\ | | **BatteryGranularityInformation**

1 | An array of [**BATTERY\_REPORTING\_SCALE**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-battery_reporting_scale) structures, never more than four entries.\ | | **BatteryInformation**

0 | A [**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str) structure.\ | | **BatteryManufactureDate**

5 | A [**BATTERY\_MANUFACTURE\_DATE**](https://learn.microsoft.com/windows/win32/power/battery-manufacture-date-str) structure.\ | | **BatteryManufactureName**

6 | Null-terminated Unicode string that specifies the name of the manufacturer of the battery.\ | | **BatterySerialNumber**

8 | Null-terminated Unicode string that specifies the battery's serial number.\ | | **BatteryTemperature**

2 | A **ULONG** that specifies the battery's current temperature, in 10ths of a degree Kelvin.\ | | **BatteryUniqueID**

7 | Null-terminated Unicode string that uniquely identifies the battery. This value can be used to track a specific battery. In the case of smart batteries, this ID would be the concatenation of the manufacturer's name, device name, date of manufacture, and a printable representation of the serial number. \ This value is not intended to be displayed to the user.\ |

**AtRate**

This member is used only if **InformationLevel** is BatteryEstimatedTime.

If this member is nonzero, it is a rate of drain that will be used to calculate the time until the battery is discharged for the BatteryEstimatedTime of an individual battery. It must be specified in mW, and must be a negative value to represent a battery discharge rate.

## Remarks

Some information about batteries is optional or may be meaningless for some batteries. If the particular type of data requested is not available for the current battery, then ERROR\_INVALID\_FUNCTION is returned.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str) [**BATTERY\_MANUFACTURE\_DATE**](https://learn.microsoft.com/windows/win32/power/battery-manufacture-date-str) [**BATTERY\_REPORTING\_SCALE**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-battery_reporting_scale) [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information) [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag)