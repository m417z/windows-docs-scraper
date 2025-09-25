# KeEnterCriticalRegion function (wdm.h)

## Description

The **KeEnterCriticalRegion** routine temporarily disables the execution of normal kernel APCs, but does not prevent special kernel APCs from running.

## Remarks

A driver calls this routine to enter a critical region in which the execution of normal kernel APCs is deferred until this driver exits the critical region by calling the [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion) routine. Any caller of **KeEnterCriticalRegion** should call **KeLeaveCriticalRegion** as quickly as possible after entering a critical region.

Highest-level drivers can call **KeEnterCriticalRegion** while running in the context of the thread that requested the current I/O operation.

A thread that is inside a critical region has both user APCs and normal kernel APCs disabled, but not special kernel APCs. For more information about these APC types, see [Types of APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs).

Critical regions can be entered recursively and each call to **KeEnterCriticalRegion** must have a matching call to **KeLeaveCriticalRegion**.

A driver can use a critical region to acquire and release exclusive access to a shared resource. In this case, the [ExEnterCriticalRegionAndAcquireResourceExclusive](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn308550(v=vs.85)) and [ExReleaseResourceAndLeaveCriticalRegion](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn308551(v=vs.85)) routines can be used instead of the **KeEnterCriticalRegion** and **KeLeaveCriticalRegion** routines. For more information, see the code example in [ExEnterCriticalRegionAndAcquireResourceExclusive](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn308550(v=vs.85)).

For more information about APCs, see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/asynchronous-procedure-calls).

## See also

[ExEnterCriticalRegionAndAcquireResourceExclusive](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn308550(v=vs.85))

[ExReleaseResourceAndLeaveCriticalRegion](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn308551(v=vs.85))

[KeAreApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keareapcsdisabled)

[KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion)