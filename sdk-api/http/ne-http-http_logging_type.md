# HTTP_LOGGING_TYPE enumeration

## Description

The **HTTP_LOGGING_TYPE** enumeration defines the type of logging that is performed.

This enumeration is used in the [HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info) structure.

## Constants

### `HttpLoggingTypeW3C`

The log format is W3C style extended logging. Applications choose the fields that are logged in the **Fields** member of the [HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info) structure.

 When this type of logging is set on a URL Group, logging is similar to the IIS6 site logging. When set on a server session this format functions as a centralized logging for all of the URL Groups.

### `HttpLoggingTypeIIS`

The log format is IIS5/6 style logging. This format has a fixed field definition; applications cannot choose which fields are logged. This format cannot be chosen when setting the logging property on a server session.

### `HttpLoggingTypeNCSA`

The log format is NCSA style logging. This format has a fixed field definition; applications cannot choose which fields are logged. This format cannot be chosen when setting the logging property on a server session.

### `HttpLoggingTypeRaw`

The log format is centralized binary logging. This format has a fixed field definition; applications cannot choose which fields are logged. This format cannot be chosen when setting the logging property on a URL Group.

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

For more information about the log file formats, see [IIS Log File Formats](https://learn.microsoft.com/previous-versions/iis/6.0-sdk/ms525807(v=vs.90)).

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info)