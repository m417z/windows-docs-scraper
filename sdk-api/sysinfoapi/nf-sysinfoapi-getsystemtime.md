# GetSystemTime function

## Description

Retrieves the current system date and time in Coordinated Universal Time (UTC) format.

To retrieve the current system date and time in local time, use the [GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime) function.

## Parameters

### `lpSystemTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure to receive the current system date and time. The *lpSystemTime* parameter must not be **NULL**. Using **NULL** will result in an access violation.

## Remarks

To set the current system date and time, use the [SetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtime) function.

#### Examples

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

```dos
// Sample output

The system time is: 19:34
 The local time is: 12:34
```

For more information about this example, see
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime).

## See also

[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)

[GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment)

[GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtime)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)