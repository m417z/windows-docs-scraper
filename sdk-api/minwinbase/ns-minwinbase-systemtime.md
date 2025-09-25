# SYSTEMTIME structure

## Description

Specifies a date and time, using individual members for the month, day, year, weekday, hour, minute, second, and millisecond. The time is either in coordinated universal time (UTC) or local time, depending on the function that is being called.

## Members

### `wYear`

 The year. The valid values for this member are 1601 through 30827.

### `wMonth`

The month. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 1 | January |
| 2 | February |
| 3 | March |
| 4 | April |
| 5 | May |
| 6 | June |
| 7 | July |
| 8 | August |
| 9 | September |
| 10 | October |
| 11 | November |
| 12 | December |

### `wDayOfWeek`

The day of the week. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |

### `wDay`

The day of the month. The valid values for this member are 1 through 31.

### `wHour`

The hour. The valid values for this member are 0 through 23.

### `wMinute`

The minute. The valid values for this member are 0 through 59.

### `wSecond`

The second. The valid values for this member are 0 through 59.

### `wMilliseconds`

The millisecond. The valid values for this member are 0 through 999.

## Remarks

> [!NOTE]
> The **SYSTEMTIME** does not check to see if the date represented is a real and valid date. When working with this API, you should ensure its validity, especially in leap year scenarios. See [leap day readiness](https://techcommunity.microsoft.com/t5/azure-developer-community-blog/it-s-2020-is-your-code-ready-for-leap-day/ba-p/1157279) for more information.

It is not recommended that you add and subtract values from the
**SYSTEMTIME** structure to obtain relative times. Instead, you should

* Convert the
  **SYSTEMTIME** structure to a
  [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.
* Copy the resulting
  [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to a
  [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) structure.
* Use normal 64-bit arithmetic on the [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) value.

The system can periodically refresh the time by synchronizing with a time source. Because the system time can be adjusted either forward or backward, do not compare system time readings to determine elapsed time. Instead, use one of the methods described in
[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time).

#### Examples

The following example demonstrates the difference between the time values retrieved by the [GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime) and [GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime) functions.

```cpp
#include <windows.h>
#include <stdio.h>

void main()
{
    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    GetLocalTime(&lt);

    printf("The system time is: %02d:%02d\n", st.wHour, st.wMinute);
    printf(" The local time is: %02d:%02d\n", lt.wHour, lt.wMinute);
}

```

``` syntax
// Sample output

The system time is: 19:34
 The local time is: 12:34

```

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[SetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setlocaltime)

[SetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtime)

[SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1)