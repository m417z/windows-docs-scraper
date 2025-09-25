# StopWatchMode function

## Description

[**StopWatchMode** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves a value that indicates which performance information is being logged.

## Return value

Type: **DWORD**

The current stopwatch mode. If performance information is not being logged, then the stopwatch mode is zero. Otherwise, it consists of one or more of the following flags.

| Flag | Value | Description |
| --- | --- | --- |
| SPMODE_SHELL | 0x00000001 | Logs selected Windows Explorer actions. |
| SPMODE_DEBUGOUT | 0x00000002 | Has no effect. |
| SPMODE_TEST | 0x00000004 | Has no effect. |
| SPMODE_BROWSER | 0x00000008 | Logs selected activities of the Windows Explorer or Internet Explorer browser frame. This flag cannot be combined with SPMODE_EVENTTRACE. |
| SPMODE_FLUSH | 0x00000010 | Has no effect. |
| SPMODE_EVENT | 0x00000020 | Has no effect. |
| SPMODE_MSVM | 0x00000040 | Logs selected times for initializing the Microsoft VM. |
| SPMODE_FORMATTEXT | 0x00000080 | Windows 2000: Indicates in the log which entries affect the browser frame.<br><br>Windows XP: Has no effect. |
| SPMODE_PROFILE | 0x00000100 | Has no effect. |
| SPMODE_DEBUGBREAK | 0x00000200 | Breaks into the debugger after each log entry is created. If there is no debugger available, the program halts with a STATUS_BREAKPOINT exception. |
| SPMODE_MSGTRACE | 0x00000400 | Enables message performance logs. |
| SPMODE_PERFTAGS | 0x00000800 | Has no effect. |
| SPMODE_MEMWATCH | 0x00001000 | Has no effect. |
| SPMODE_DBMON | 0x00002000 | Has no effect. |
| SPMODE_MULTISTOP | 0x00004000 | Logs all "stop" operations even if there is only one matching "start". |
| SPMODE_EVENTTRACE | 0x00008000 | Logs selected activities of the MSHTML rendering engine. This flag cannot be combined with SPMODE_BROWSER. |

## Remarks

To enable performance logging, set the following REG_DWORD registry value. You should restart your computer after setting this value, to ensure that the change has taken effect.

```
HKEY_LOCAL_MACHINE
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  Performance
                     Mode
```

The information in the performance log is intended for internal measurement purposes and the exact contents change regularly. Performance logging in its current form is subject to change in the future.

Enabling performance logging degrades performance slightly.

**Note** When using Windows XP with Service Pack 2 (SP2) and later, performance data is not collected for a process until that process calls the **StopWatchMode** function for the first time, even if the above registry value has been set to a nonzero value.

## See also

[StopWatchFlush](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-stopwatchflush)