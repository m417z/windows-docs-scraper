# TIME_OF_DAY_INFO structure

## Description

The
**TIME_OF_DAY_INFO** structure contains information about the time of day from a remote server.

## Members

### `tod_elapsedt`

Type: **DWORD**

The number of seconds since 00:00:00, January 1, 1970, GMT.

### `tod_msecs`

Type: **DWORD**

The number of milliseconds from an arbitrary starting point (system reset).

Typically, this member is read twice, once when the process begins and again at the end. To determine the elapsed time between the process's start and finish, you can subtract the first value from the second.

### `tod_hours`

Type: **DWORD**

The current hour. Valid values are 0 through 23.

### `tod_mins`

Type: **DWORD**

The current minute. Valid values are 0 through 59.

### `tod_secs`

Type: **DWORD**

The current second. Valid values are 0 through 59.

### `tod_hunds`

Type: **DWORD**

The current hundredth second (0.01 second). Valid values are 0 through 99.

### `tod_timezone`

Type: **LONG**

The time zone of the server. This value is calculated, in minutes, from Greenwich Mean Time (GMT). For time zones west of Greenwich, the value is positive; for time zones east of Greenwich, the value is negative. A value of –1 indicates that the time zone is undefined.

### `tod_tinterval`

Type: **DWORD**

The time interval for each tick of the clock. Each integral integer represents one ten-thousandth second (0.0001 second).

### `tod_day`

Type: **DWORD**

The day of the month. Valid values are 1 through 31.

### `tod_month`

Type: **DWORD**

The month of the year. Valid values are 1 through 12.

### `tod_year`

Type: **DWORD**

The year.

### `tod_weekday`

Type: **DWORD**

The day of the week. Valid values are 0 through 6, where 0 is Sunday, 1 is Monday, and so on.

## See also

[NetRemoteTOD](https://learn.microsoft.com/windows/desktop/api/lmremutl/nf-lmremutl-netremotetod)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Remote Utility functions](https://learn.microsoft.com/windows/desktop/NetMgmt/remote-utility-functions)