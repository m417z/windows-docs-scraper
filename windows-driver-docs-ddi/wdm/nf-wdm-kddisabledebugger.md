# KdDisableDebugger function

## Description

The **KdDisableDebugger** routine disables the kernel debugger.

## Return value

**KdDisableDebugger** returns STATUS_SUCCESS if the kernel debugger was successfully disabled. Otherwise, the return value can be one of the following error status codes:

STATUS_ACCESS_DENIED

STATUS_DEBUGGER_INACTIVE

## Remarks

If the operating system was booted with no debug controls, **KdDisableDebugger** returns STATUS_DEBUGGER_INACTIVE.

If the kernel debugger is blocked (that is, the **KdBlockEnable** system variable is set to a value other than **FALSE**), **KdDisableDebugger** returns STATUS_ACCESS_DENIED.

After a caller calls **KdDisableDebugger** to disable the kernel debugger, the caller can call the [KdEnableDebugger](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdenabledebugger) routine to re-enable the kernel debugger.

## See also

[KdEnableDebugger](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdenabledebugger)