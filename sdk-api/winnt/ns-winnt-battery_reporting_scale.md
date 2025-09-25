# BATTERY_REPORTING_SCALE structure

## Description

Contains the granularity of the battery capacity that is reported by [IOCTL_BATTERY_QUERY_STATUS](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-status). A variable-length array of **BATTERY_REPORTING_SCALE** structures is returned from [IOCTL_BATTERY_QUERY_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-information) when the **InformationLevel** is set to **BatteryGranularityInformation**. Multiple entries are returned when the granularity depends on the present capacity of the battery.

## Members

### `Granularity`

The granularity of the capacity reading returned by [IOCTL_BATTERY_QUERY_STATUS](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-status) in milliwatt-hours (mWh). Granularity may change over time as battery discharge and recharge lowers the range of readings.

### `Capacity`

The upper capacity limit for *Granularity*. The value of *Granularity* is valid for capacities reported by [IOCTL_BATTERY_QUERY_STATUS](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-status) that are less than or equal to this capacity (mWh), but greater than or equal to the capacity given in the previous array element, or zero if this is the first array element.

## Remarks

The total number of **BATTERY_REPORTING_SCALE** entries returned from [IOCTL_BATTERY_QUERY_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-information) is indicated by the value of the *lpBytesReturned* parameter of [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol). To determine the number of elements in the array, divide the value of *lpBytesReturned* by the size of the
**BATTERY_REPORTING_SCALE** structure. The maximum number of array entries that can be returned is four.

## See also

[IOCTL_BATTERY_QUERY_INFORMATION](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-information)

[IOCTL_BATTERY_QUERY_STATUS](https://learn.microsoft.com/windows/desktop/Power/ioctl-battery-query-status)