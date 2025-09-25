# _MSFC_TM structure

## Description

The MSFC_TM structure is used by WMI providers to timestamp events.

## Members

### `tm_sec`

Indicates the number of seconds past the minute. This member must have a value between 0 and 59.

### `tm_min`

Indicates the number of minutes after the hour. This member must have a value between 0 and 59.

### `tm_hour`

Indicates the number of hours since midnight. This member must have a value between 0 and 23.

### `tm_mday`

Indicates the day of the month. This member must have a value between 1 and 31.

### `tm_mon`

Indicates the number of months since January. This member must have a value between 0 and 11.

### `tm_year`

Indicates the number of years since 1900.

### `tm_wday`

Indicates the number of days since Sunday. This member must have a value between 0 and 6.

### `tm_yday`

Indicates the number of days since January 1. This member must have a value between 0 and 365.

### `tm_isdst`

Indicates when **TRUE** that the time stamp complies with daylight savings time. When **FALSE**, indicates that the timestamp does not comply with daylight savings time.

## See also

[MSFC_TM WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-tm-wmi-class)