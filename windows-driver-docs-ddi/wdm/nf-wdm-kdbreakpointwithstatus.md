# KdBreakPointWithStatus macro

## Description

The **KdBreakPointWithStatus** macro breaks into the kernel debugger and sends the value of *Status* to the debugger.

## Parameters

### `s` [in]

Specifies a ULONG value to be sent to the debugger (for example, a status code or an address).

## Remarks

**KdBreakPointWithStatus** is identical to the [DbgBreakPointWithStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgbreakpointwithstatus) routine in code that is compiled for a debug configuration. This routine has no effect if compiled in a release configuration.

On x86 computers, the *Status* parameter is stored in the **eax** register. On computers that have register calling conventions, *Status* is stored in the first argument register.

This routine raises an exception that is handled by the kernel debugger if one is installed; otherwise it is handled by the debug system. If a debugger is not connected to the system, the exception can be handled in the standard way.

In kernel mode, a break exception that is not handled will cause a bug check. You can, however, connect a kernel-mode debugger to a target computer that has stopped responding and has kernel debugging enabled. For more information, see [Windows Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/).

## See also

[DbgBreakPoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgbreakpoint)

[DbgBreakPointWithStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgbreakpointwithstatus)

[KdBreakPoint](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548063(v=vs.85))

[Windows Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/)