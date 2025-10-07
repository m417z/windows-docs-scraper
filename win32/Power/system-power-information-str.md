# SYSTEM\_POWER\_INFORMATION structure

Contains information about the idleness of the system.

## Members

**MaxIdlenessAllowed**

The idleness at which the system is considered idle and the idle time-out begins counting, expressed as a percentage. Dropping below this number causes the timer to be canceled.

**Idleness**

The current idle level, expressed as a percentage.

**TimeRemaining**

The time remaining in the idle timer, in seconds.

**CoolingMode**

The current system cooling mode. This member must one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **PO\_TZ\_ACTIVE**

0 | The system is currently in Active cooling mode.\ | | **PO\_TZ\_INVALID\_MODE**

2 | The system does not support CPU throttling, or there is no thermal zone defined in the system.\ | | **PO\_TZ\_PASSIVE**

1 | The system is currently in Passive cooling mode.\ |

## Remarks

Note that this structure definition was accidentally omitted from WinNT.h. This error will be corrected in the future. In the meantime, to compile your application, include the structure definition contained in this topic in your source code.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CallNtPowerInformation**](https://learn.microsoft.com/windows/desktop/api/Powerbase/nf-powerbase-callntpowerinformation)

