# BATTERY\_SET\_INFORMATION structure

Contains battery information to be set. This structure is used with the [**IOCTL\_BATTERY\_SET\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-set-information) control code.

## Members

**BatteryTag**

The current battery tag for the battery. Information for a battery matching the tag can only be returned. Whenever this value does not match the battery's current tag, the IOCTL request will be completed with ERROR\_FILE\_NOT\_FOUND, which indicates to the caller that the battery for which it has a tag for no longer exists. The caller may opt to use the [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag) operation to determine the tag of the newly installed battery, if one exists. (See [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information.)

When a query information request is made, this value is verified. In addition, if the request is in progress while this value changes, the request is aborted with the status of ERROR\_FILE\_NOT\_FOUND.

**InformationLevel**

The battery information to be set. The type of data in the **Buffer** member depends on the value of this member. This member can be one of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**BatteryCharge**

1

| Informs the battery device that the user has requested that the battery should be charging at this time. For example, with a smart battery/charger/selector, the application could charge one battery at a time. The **Buffer** member of this structure is ignored.<br> |
|

**BatteryCriticalBias**

0

| Sets the battery's critical bias adjustment. Note it is not envisioned that this value would normally be changed by software, and is present in the interfaces only as a maintenance feature. Not all batteries can maintain such a setting, and the battery information should be read to confirm that the battery accepted the setting.<br> |
|

**BatteryDischarge**

2

| Informs the battery device that the user has requested that the battery be discharging at this time. For example, this could be used to indicate which battery the user currently wants to power the system. The **Buffer** member of this structure is ignored.<br> |

**Buffer**

The battery information to be set. The data depends on the value of **InformationLevel**.

## Remarks

The **BATTERY\_SET\_INFORMATION** structure is a variable-length structure, and you must allocate a buffer of suitable size for the information to be included in the structure.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [**IOCTL\_BATTERY\_SET\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-set-information)