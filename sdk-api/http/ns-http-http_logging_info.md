# HTTP_LOGGING_INFO structure

## Description

The **HTTP_LOGGING_INFO** structure is used to enable server side logging on a URL Group or on a server session.

This structure must be used when setting or querying the [HttpServerLoggingProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group or server session.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure that specifies whether the property is present.

### `LoggingFlags`

The optional logging flags change the default logging behavior.

These can be one or more of the following [HTTP_LOGGING_FLAG](https://learn.microsoft.com/windows/desktop/Http/http-logging-flag--constants) values:

| Value | Meaning |
| --- | --- |
| **HTTP_LOGGING_FLAG_LOCAL_TIME_ROLLOVER** | Changes the log file rollover time to local time. By default log file rollovers are based on GMT. |
| **HTTP_LOGGING_FLAG_USE_UTF8_CONVERSION** | By default, the unicode logging fields are converted to multibytes using the systems local code page. If this flags is set, the UTF8 conversion is used instead. |
| **HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY** | The log errors only flag enables logging errors only. By default, both error and success request are logged.<br><br>The **HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY** and **HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY** flags are used to perform selective logging. Only one of these flags can be set at a time; they are mutually exclusive. |
| **HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY** | The log success only flag enables logging successful requests only. By default, both error and success request are logged.<br><br>The **HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY** and **HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY** flags are used to perform selective logging. Only one of these flags can be set at a time; they are mutually exclusive. |

### `SoftwareName`

The optional software name string used in W3C type logging. This name is not used for other types of logging. If this parameter is **NULL**, the HTTP Server API logs a default string.

### `SoftwareNameLength`

The length, in bytes, of the software name. The length cannot be greater than **MAX_PATH**.

If the **SoftwareName** member is **NULL**, this length must be zero.

### `DirectoryNameLength`

The length, in bytes, of the directory name. The length cannot be greater than 424 bytes.

### `DirectoryName`

The logging directory under which the log files are created. The directory string must be a fully qualified path including the drive letter.

 Applications can use a UNC path to a remote machine to enable UNC logging.

### `Format`

A member of the [HTTP_LOGGING_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_logging_type) enumeration specifying one of the following log file formats.

| Format | Meaning |
| --- | --- |
| **HttpLoggingTypeW3C** | The log format is W3C style extended logging. With this format, application can pick a combination of log fields to be logged. When W3C logging is set on a URL group, logging is similar to the IIS6 site logging. When W3C logging is set on a server session, this logging functions as a centralized logging for all of the URL Groups. |
| **HttpLoggingTypeIIS** | The log format is IIS6/5 style logging. This format has fixed field definitions; applications cannot select the fields that are logged. This format cannot be used for logging a server session. |
| **HttpLoggingTypeNCSA** | The log format is NCSA style logging. This format has fixed field definitions; applications cannot select the fields that are logged. This format cannot be used for logging a server session. |
| **HttpLoggingTypeRaw** | The log format is centralized binary logging. This format has fixed field definitions; applications cannot select the fields that are logged. This format cannot be used for logging a URL Group. |

### `Fields`

The fields that are logged when the format is set to W3C. These can be one or more of the [HTTP_LOG_FIELD_ Constants](https://learn.microsoft.com/windows/desktop/Http/http-log-field--constants) values.

When the logging format is W3C is , applications must specify the log fields otherwise no fields are logged.

### `pExtFields`

Reserved. Set to 0 (zero) or **NULL**.

### `NumOfExtFields`

Reserved. Set to 0 (zero) or **NULL**.

### `MaxRecordSize`

Reserved. Set to 0 (zero) or **NULL**.

### `RolloverType`

One of the following members of the [HTTP_LOGGING_ROLLOVER_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_logging_rollover_type) enumeration specifying the criteria for log file rollover.

| Rollover Type | Meaning |
| --- | --- |
| **HttpLoggingRolloverSize** | The log files are rolled over when they reach or exceed a specified size. |
| **HttpLoggingRolloverDaily** | The log files are rolled over every day. |
| **HttpLoggingRolloverWeekly** | The log files are rolled over every week. |
| **HttpLoggingRolloverMonthly** | The log files are rolled over every month. |
| **HttpLoggingRolloverHourly** | The log files are rolled over every hour. |

### `RolloverSize`

The maximum size, in bytes, after which the log files is rolled over. A value of **HTTP_LIMIT_INFINITE** indicates an unlimited size. The minimum value cannot be smaller than **HTTP_MIN_ALLOWED_LOG_FILE_ROLLOVER_SIZE** (1024 * 1024).

This field is used only for **HttpLoggingRolloverSize** rollover type and should be set to zero for all other types.

When rollover type is **HttpLoggingRolloverSize**, applications must specify the maximum size for the log file.

### `pSecurityDescriptor`

The security descriptor that is applied to the log files directory and all sub-directories. If this member is **NULL**, either the system default ACL is used or the ACL is inherited from the parent directory.

## Remarks

The [HttpServerLoggingProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) property sets one of four types of server side logging: HttpLoggingTypeW3C, HttpLoggingTypeIIS, HttpLoggingTypeNCSA, or HttpLoggingTypeRaw. When this property is set on a server session it functions as centralized form of logging for all of the URL groups under that server session. Requests that are routed to one of the URL groups under the server session are logged in one centralized log file. The configuration parameters for the log file are passed in the **HTTP_LOGGING_INFO** structure in the call to [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty).

When this property is set on a URL Group, logging is performed only on requests that are routed to the URL Group.
Log files are created when the request arrives on the URL Group or server session, they are not created when logging is configured.

Applications must ensure that the directory specified in the **DirectoryName** member is unique.

The log files names are based on the specified rollover type. The following table shows the naming conventions for log files.

| Format | Rollover type | File name pattern |
| --- | --- | --- |
| Microsoft IIS Log Format | Size | inetsvnn.log |
|  | Hourly | inyymmddhh.log |
|  | Daily | inyymmdd.log |
|  | Weekly | inyymmww.log |
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

The letters yy, mm, ww, dd, hh, and nn in the table represent the following digits:

* yy: The two digit representation of the year.
* mm: The two digit representation of the month.
* ww: The two digit representation of the week.
* dd: The two digit representation of the day.
* hh: The two digit representation of the hour in 24 hour notation.
* nn: The two digit representation of the numerical sequence.

Please note that in the HTTP version 2.0 API, the [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) and [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) have been revisioned to allow applications to pass an [HTTP_LOG_FIELDS_DATA](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_log_fields_data) structure so the response can be logged. Setting the **HttpServerLoggingProperty** property on a server session or a URL group does not mean that HTTP responses are logged. Logging on the URL group or the server session will not take place unless the calls to **HttpSendResponseEntityBody** and **HttpSendHttpResponse** include an optional **HTTP_LOG_FIELDS_DATA** structure. For more information, see the **HTTP_LOG_FIELDS_DATA** topic.

For information on the log file formats, see the [IIS Log File Formats](https://learn.microsoft.com/previous-versions/iis/6.0-sdk/ms525807(v=vs.90)) topic.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_LOGGING_FLAG_ Constants](https://learn.microsoft.com/windows/desktop/Http/http-logging-flag--constants)

[HTTP_LOGGING_ROLLOVER_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_logging_rollover_type)

[HTTP_LOGGING_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_logging_type)

[HTTP_LOG_FIELD_ Constants](https://learn.microsoft.com/windows/desktop/Http/http-log-field--constants)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpShutdownRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpshutdownrequestqueue)