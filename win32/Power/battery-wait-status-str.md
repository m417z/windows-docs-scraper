# BATTERY\_WAIT\_STATUS structure

Contains information about the conditions under which the battery status is to be retrieved. This structure is used by the [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status) control code.

## Members

**BatteryTag**

The current battery tag for the battery. Only information for a battery matching the tag can be returned. Whenever this value does not match the battery's current tag, the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) operation will fail with an error code of ERROR\_FILE\_NOT\_FOUND, which indicates to the caller that the battery for which it has a tag is no longer installed The caller may opt to use the [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag) operation to determine the tag of the newly installed battery, if any. In addition, if the request is in progress when the battery is removed, or the tag changes, the operation is aborted with the status of ERROR\_FILE\_NOT\_FOUND. (See [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information.)

**Timeout**

The number of milliseconds the request will wait for the condition specified by the **PowerState**, **LowCapacity**, and **HighCapacity** members before completing. A value of -1 indicates that the request will wait indefinitely for the conditions to be satisfied. A value of zero indicates that the requested battery information is to be returned immediately, regardless of the other conditions. Any other value indicates that the request should wait that length of time, or until any one of the other conditions is satisfied.

If the computer has entered sleep mode, the clock will continue to run, but exhausting the count will not wake the computer up. If the count is exhausted when the computer is awoken, and other conditions are satisfied, the call will return immediately on awakening.

**PowerState**

Zero, one, or more of the following status bits, which indicate the state of the battery. It is identical to the **PowerState** member of the [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) structure.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| **BATTERY\_CHARGING**

0x00000004 | Indicates that the battery is currently charging.\ | | **BATTERY\_CRITICAL**

0x00000008 | Indicates that battery failure is imminent. See the Remarks section for more information.\ | | **BATTERY\_DISCHARGING**

0x00000002 | Indicates that the battery is currently discharging.\ | | **BATTERY\_POWER\_ON\_LINE**

0x00000001 | Indicates that the battery has access to AC power.\ |

**LowCapacity**

The current battery capacity, in mWh (or relative). This value is identical to the **Capacity** member of the [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) structure.

**HighCapacity**

The current battery capacity, in mWh (or relative). This value is identical to the **Capacity** member of the [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) structure.

## Remarks

Requests for battery information are postponed until one of the following occurs:

- The time-out expires (assuming **Timeout** is not -1).
- The battery's current status does not match **PowerState**.
- The battery's capacity is below **LowCapacity**.
- The battery's capacity is above **HighCapacity**.
- The battery tag changes.

When any one of these conditions is satisfied, the data is collected and the operation returns. This allows applications to monitor typical dynamic battery information without polling the device.

Before using either of the two Capacity conditions, make sure the battery supports them by using the [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status) control code with a time-out of zero. Examine the results to determine if the **Capacity** member is supported (that is, not BATTERY\_UNKNOWN\_CAPACITY).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status) [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag)