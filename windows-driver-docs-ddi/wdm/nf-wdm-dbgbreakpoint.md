# DbgBreakPoint function

## Description

The **DbgBreakPoint** routine breaks into the kernel debugger.

## Return value

None

## Remarks

The **DbgBreakPoint** routine is the kernel-mode equivalent of **DebugBreak**.

This routine raises an exception that is handled by the kernel debugger if one is installed; otherwise, it is handled by the debug system. If a debugger is not connected to the system, the exception can be handled in the standard way.

In kernel mode, a break exception that is not handled will cause a bug check. You can, however, connect a kernel-mode debugger to a target computer that has stopped responding and has kernel debugging enabled. For more information, see [Windows Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/).

## See also

[DbgBreakPointWithStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgbreakpointwithstatus)

[KdBreakPoint](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548063(v=vs.85))

[KdBreakPointWithStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdbreakpointwithstatus)