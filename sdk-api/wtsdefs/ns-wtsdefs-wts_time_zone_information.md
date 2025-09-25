# WTS_TIME_ZONE_INFORMATION structure

## Description

Contains client time zone information.

## Members

### `Bias`

An integer that contains the bias for local time translation. Bias is the difference, in minutes, between Coordinated Universal Time (Greenwich Mean Time) and local time.

### `StandardName`

A string that contains a descriptive name for standard time on the client. Examples include "Pacific Standard Time".

### `StandardDate`

A [WTS_SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_systemtime) structure that contains the date and local time when the transition from daylight saving time to standard time occurs on the client. If this field is specified, the **DaylightDate** member should also be specified.

### `StandardBias`

An integer that defines the bias, in minutes, to be used during local time translations that occur during standard time. This value is added to the value of the **Bias** member to form the bias used during standard time. In most time zones, the value of this field is zero.

### `DaylightName`

A string that contains a descriptive name for daylight saving time on the client. Examples include "Pacific Daylight Time".

### `DaylightDate`

A [WTS_SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_systemtime) structure that contains the date and local time when the transition from standard time to daylight saving time occurs on the client. If this field is specified, the **StandardDate** member should also be specified.

### `DaylightBias`

An integer that defines the bias, in minutes, to be used during local time translations that occur during daylight saving time. This value is added to the value of the **Bias** member to form the bias used during daylight saving time. In most time zones, the value of this field is 60.