## Description

The **KdRefreshDebuggerNotPresent** macro refreshes the value of the [KD_DEBUGGER_NOT_PRESENT](https://learn.microsoft.com/previous-versions/ff548125(v=vs.85)) global kernel variable.

## Return value

**KdRefreshDebuggerNotPresent** returns the value of KD_DEBUGGER_NOT_PRESENT.

## Remarks

When **KdRefreshDebuggerNotPresent** is called, it forces the value of KD_DEBUGGER_NOT_PRESENT to be updated to reflect whether a kernel debugger is currently attached. This updated value is also used as the return value of this routine.

If a kernel debugger was recently attached or removed, the value of KD_DEBUGGER_NOT_PRESENT may not reflect the new state. If you suspect this has happened, you should call **KdRefreshDebuggerNotPresent** to refresh the value of this variable. After this call, you may use either the value of KD_DEBUGGER_NOT_PRESENT or the return value of **KdRefreshDebuggerNotPresent** to determine if the kernel debugger is present.

KD_DEBUGGER_NOT_PRESENT can be modified by Windows or any other kernel-mode binary. Therefore, it is possible that the most recent return value of **KdRefreshDebuggerNotPresent** may not match the current value of KD_DEBUGGER_NOT_PRESENT.

The following sample shows how to use **KdRefreshDebuggerNotPresent**:

```cpp
if (KdRefreshDebuggerNotPresent() == FALSE)
{
    //  A kernel debugger is active.
    DbgPrint("A problem occurred\n");
 DbgBreakPoint();
}
else
{
 //  No kernel debugger attached, or kernel debugging not enabled.
 KeBugCheckEx(...);
}
```

## See also

[Determining if a Debugger is Attached](https://learn.microsoft.com/windows-hardware/drivers/debugger/determining-if-a-debugger-is-attached)

[KD_DEBUGGER_ENABLED](https://learn.microsoft.com/previous-versions/ff548118(v=vs.85))

[KD_DEBUGGER_NOT_PRESENT](https://learn.microsoft.com/previous-versions/ff548125(v=vs.85))