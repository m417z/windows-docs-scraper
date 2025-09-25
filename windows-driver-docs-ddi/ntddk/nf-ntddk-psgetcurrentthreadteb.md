# PsGetCurrentThreadTeb function

## Description

The **PsGetCurrentThreadTeb** routine returns the Thread Environment Block (TEB) of the current thread, or NULL. The call must be made in kernel-mode.

## Return value

A pointer to the thread environment block of the current thread. The TEB should be accessed within a try/catch exception block.

**PsGetCurrentThreadTeb** returns NULL in the following cases:

* The current thread does not have a TEB (for example a system thread).
* The current thread cannot safely access its own TEB. This might happen if the driver attached the thread to the address space of another process, for example by calling [**KeStackAttachProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess).

## Remarks

While **PsGetCurrentThreadTeb** can be called at any IRQL without causing a bugcheck, the TEB is not safe to access at DISPATCH_LEVEL or above (it could be paged out).
Also, if you're calling at elevated IRQL from the context of an interrupt or DPC, the current thread is whatever happened to be running on the current processor when your interrupt was delivered there.
As a result, it is recommended that you call **PsGetCurrentThreadTeb** from thread context below DISPATCH_LEVEL.

## See also

[Process and Thread Manager Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)