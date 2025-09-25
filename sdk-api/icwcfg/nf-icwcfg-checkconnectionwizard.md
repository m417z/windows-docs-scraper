# CheckConnectionWizard function

## Description

[This function is unsupported and may be altered or unavailable in future versions of Windows. ]

The **CheckConnectionWizard** function checks that the Internet Connection Wizard (ICW) is installed and that it has not been run
before. **CheckConnectionWizard** then either runs the ICW or returns the status of the ICW as specified by the run flags provided and the status of any previous run of the ICW.

## Parameters

### `unnamedParam1`

A combination of bit flags that indicates the action **CheckConnectionWizard** is to perform.

| Value | Meaning |
| --- | --- |
| **ICW_CHECKSTATUS**<br><br>0x0001 | Check if the ICW is present and if it has been run. |
| **ICW_LAUNCHFULL**<br><br>0x0100 | Check if the ICW is present and the retail mode ISP signup is available and, if possible, run the ICW. |
| **ICW_LAUNCHMANUAL**<br><br>0x0200 | Check if the ICW is present, run the ICW in Internet Explorer Administrator Kit (IEAK) Kiosk mode. |
| **ICW_USE_SHELLNEXT**<br><br>0x0400 | If the retail mode ISP signup is present, run the ICW using the value set in the **ShellNext** registry key by [SetShellNext](https://learn.microsoft.com/windows/desktop/api/icwcfg/nf-icwcfg-setshellnext) function. |
| **ICW_FULL_SMARTSTART**<br><br>0x800 | If the ICW is present, the retail mode ISP signup is available, and **ICW_LAUNCHFULL** is specified, run the ICW with the *smartstart* command line parameter. |

### `unnamedParam2`

**DWORD** in which the results of the call are returned. The value is a
combination of the following bit flags.

| Value | Meaning |
| --- | --- |
| **ICW_FULLPRESENT**<br><br>0x0001 | The retail mode ISP signup is present on the system. |
| **ICW_MANUALPRESENT**<br><br>0x0002 | IEAK mode is present. This is always set if **ICW_FULLPRESENT** is set. |
| **ICW_ALREADYRUN**<br><br>0x0004 | The ICW has been previously run to completion. |
| **ICW_LAUNCHEDFULL**<br><br>0x0100 | The retail mode ISP signup ICW was started. |
| **ICW_LAUNCHEDMANUAL**<br><br>0x0200 | The IEAK mode of ICW was started. |

## Return value

**ERROR_SUCCESS** indicates a successful call.
Any other value indicates failure.

## Remarks

If the ICW is present but has not been run to completion, **CheckConnectionWizard** does one of
the following based on the value of *dwRunFlags*: returns, runs
the full ICW in retail mode ISP signup, or runs ICW in the IEAK mode.

The retail mode ISP signup is run using Icwconn1.exe. IEAK mode is run using Isign32.exe.

**Note** The calling application should exit if **ICW_LAUNCHEDFULL** or
**ICW_LAUNCHEDMANUAL** is set. The ICW may cause the system to
reboot if required system software needs to be installed.

## See also

[SetShellNext](https://learn.microsoft.com/windows/desktop/api/icwcfg/nf-icwcfg-setshellnext)