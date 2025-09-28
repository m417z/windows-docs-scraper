# PsGetCurrentProcessId function

## Description

The **PsGetCurrentProcessId** routine identifies the current thread's process.

## Return value

**PsGetCurrentProcessId** returns the process ID of the process that created the current thread.

## Remarks

**PsGetCurrentProcessId** returns the process ID of the process that originally created the current thread, which is not necessarily the process that the thread is currently attached to. In scenarios where a thread may be attached to a different process context (via APC state), this can differ from `PsGetProcessId(PsGetCurrentProcess())`.

- **PsGetCurrentProcessId()** - Returns the process ID of the process that created the thread
- **PsGetProcessId(PsGetCurrentProcess())** - Returns the process ID of the process that the thread is currently attached to

Use **PsGetCurrentProcessId** when you need the ID of the process that owns the thread. Use **PsGetProcessId(PsGetCurrentProcess())** when you need the ID of the process context the thread is currently operating in.

## See also

[**IoGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[**PsGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[**PsGetCurrentThreadId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthreadid)

[**PsGetProcessId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetprocessid)

[**PsSetCreateProcessNotifyRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[**PsSetCreateThreadNotifyRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)

[**PsSetLoadImageNotifyRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)