# HTTP_LOGGING_ROLLOVER_TYPE enumeration

## Description

The **HTTP_LOGGING_ROLLOVER_TYPE** enumeration defines the log file rollover types.

This enumeration is used in the [HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info) structure.

## Constants

### `HttpLoggingRolloverSize`

The log files are rolled over when they reach a specified size.

### `HttpLoggingRolloverDaily`

The log files are rolled over every day.

### `HttpLoggingRolloverWeekly`

The log files are rolled over every week.

### `HttpLoggingRolloverMonthly`

The log files are rolled over every month.

### `HttpLoggingRolloverHourly`

The log files are rolled over every hour, based on GMT.

## Remarks

The log files are named based on the rollover type and logging format as shown in the following table.

| Format | Rollover Type | Filename Pattern |
| --- | --- | --- |
| Microsoft IIS Log Format | Size | inetsvnn.log |
|  | Hourly | inyymmddhh.log |
|  | Daily | inyymmdd.log |
|  | Weekly | inymmww.log |
|  | Monthly | inyymm.log |
| NCSA Common Log File Format | Size | ncsann.log |
|  | Hourly | ncyymmddhh.log |
|  | Daily | ncyymmdd.log |
|  | Weekly | ncyymmww.log |
|  | Monthly | ncyymm.log |
| W3C Extended Log File Format | Size | extendnn.log |
|  | Hourly | exyymmddhh.log |
|  | Daily | exyymmdd.log |
|  | Weekly | exyymmww.log |
|  | Monthly | exyymm.log |

The following table lists time element characters and what they represent.

| Item | Description |
| --- | --- |
| yy | The two digit representation of the year. |
| mm | The two digit representation of the month. |
| ww | The two digit representation of the week. |
| dd | The two digit representation of the day. |
| hh | The two digit representation of the hour in 24 hour notation. |
| nn | The two digit representation of the numerical sequence. |

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info)