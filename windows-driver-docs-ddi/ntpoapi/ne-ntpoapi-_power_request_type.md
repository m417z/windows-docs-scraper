# _POWER_REQUEST_TYPE enumeration (ntpoapi.h)

## Description

The **POWER_REQUEST_TYPE** enumeration indicates the power request type.

## Constants

### `PowerRequestDisplayRequired`

Not used by drivers. For more information, see Remarks.

### `PowerRequestSystemRequired`

Prevents the computer from automatically entering sleep mode after a period of user inactivity.

### `PowerRequestAwayModeRequired`

Not used by drivers. For more information, see Remarks.

### `PowerRequestExecutionRequired`

Not used by drivers. For more information, see Remarks.

## Remarks

This enumeration is used by the kernel-mode [PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest) and [PoSetPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerrequest) routines. Drivers that call these routines must specify the **PowerRequestSystemRequired** enumeration value.

The other three enumeration values—**PowerRequestDisplayRequired**, **PowerRequestAwayModeRequired**, and **PowerRequestExecutionRequired**—are not used by drivers. Applications specify these power request types in calls to the [PowerSetRequest](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-powersetrequest) and [PowerClearRequest](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-powerclearrequest) functions.

A **PowerRequestDisplayRequired** power request has the following effects:

* After a period of user inactivity, the session display stays on and will not automatically turn off. If the display is already turned off, the power request turns the display on.
* A screensaver will not automatically start after a period of user inactivity. If a screensaver is already running, the power request stops the screensaver.
* The session will not be automatically locked after a period of user inactivity. If the session is already locked when the driver sends the power request, the session remains locked.

While a **PowerRequestAwayModeRequired** power request is in effect, if the user tries to put the computer into sleep mode (for example, by clicking **Start** and then clicking **Sleep**), the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) turns off audio and video so that the computer appears to be in sleep mode, but the computer continues to run.

While a **PowerRequestExecutionRequired** power request is in effect, the calling process continues to run instead of being suspended or terminated by process lifetime management (PLM) mechanisms. When and how long the process is allowed to run depends on the operating system and power policy settings. This type of power request is supported starting with Windows 8.

## See also

[PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest)

[PoSetPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerrequest)

[PowerClearRequest](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-powerclearrequest)

[PowerSetRequest](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-powersetrequest)