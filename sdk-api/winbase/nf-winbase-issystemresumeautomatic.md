# IsSystemResumeAutomatic function

## Description

Determines the current state of the computer.

## Return value

If the system was restored to the working state automatically and the user is not active, the function returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

The
[PBT_APMRESUMEAUTOMATIC](https://learn.microsoft.com/windows/desktop/Power/pbt-apmresumeautomatic) event is broadcast when the system wakes automatically to handle an event. The user is generally not present. If the system detects any user activity after broadcasting the
PBT_APMRESUMEAUTOMATIC event, it will broadcast the
[PBT_APMRESUMESUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmresumesuspend) event to let applications know they can resume full interaction with the user.

## See also

[PBT_APMRESUMEAUTOMATIC](https://learn.microsoft.com/windows/desktop/Power/pbt-apmresumeautomatic)

[PBT_APMRESUMESUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmresumesuspend)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)