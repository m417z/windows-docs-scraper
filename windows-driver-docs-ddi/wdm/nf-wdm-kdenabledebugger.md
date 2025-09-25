# KdEnableDebugger function

## Description

The **KdEnableDebugger** routine re-enables the kernel debugger after a call to the [KdDisableDebugger](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kddisabledebugger) routine disables the kernel debugger.

## Return value

**KdEnableDebugger** returns STATUS_SUCCESS if the kernel debugger was successfully re-enabled. Otherwise, the return value can be one of the following error status codes:

STATUS_ACCESS_DENIED

STATUS_DEBUGGER_INACTIVE

## Remarks

If the operating system was booted with no debug controls, **KdEnableDebugger** returns STATUS_DEBUGGER_INACTIVE.

If the kernel debugger is blocked (that is, the **KdBlockEnable** system variable is set to a value other than **FALSE**), **KdEnableDebugger** returns STATUS_ACCESS_DENIED.

## See also

[KdDisableDebugger](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kddisabledebugger)