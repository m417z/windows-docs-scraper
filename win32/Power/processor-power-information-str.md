# PROCESSOR\_POWER\_INFORMATION structure

Contains information about a processor.

## Members

**Number**

The system processor number.

**MaxMhz**

The maximum specified clock frequency of the system processor, in megahertz.

**CurrentMhz**

The processor clock frequency, in megahertz. This number is the maximum specified processor clock frequency multiplied by the current processor throttle.

**MhzLimit**

The limit on the processor clock frequency, in megahertz. This number is the maximum specified processor clock frequency multiplied by the current processor thermal throttle limit.

**MaxIdleState**

The maximum idle state of this processor.

**CurrentIdleState**

The current idle state of this processor.

## Remarks

Note that this structure definition was accidentally omitted from WinNT.h. This error will be corrected in the future. In the meantime, to compile your application, include the structure definition contained in this topic in your source code.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CallNtPowerInformation**](https://learn.microsoft.com/windows/desktop/api/Powerbase/nf-powerbase-callntpowerinformation)

