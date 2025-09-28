# IoGetCurrentProcess function

## Description

The **IoGetCurrentProcess** routine returns a pointer to the current process. Call **PsGetCurrentProcess** instead of **IoGetCurrentProcess**.

## Return value

**IoGetCurrentProcess** returns a pointer to the current process.

## Remarks

This routine is identical to **PsGetCurrentProcess**:

``#define PsGetCurrentProcess IoGetCurrentProcess``

**PsGetCurrentProcess** (and **IoGetCurrentProcess**) retrieves the current process from the thread's APC state. This returns the process that the current thread is attached to, which might be different from the process that originally created the thread.

The process returned by **PsGetCurrentProcess** may differ from the process whose ID is returned by [**PsGetCurrentProcessId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid). Use **PsGetCurrentProcessId** to get the process ID of the process that created the current thread. Use **PsGetProcessId(PsGetCurrentProcess())** to get the process ID of the process that the thread is currently attached to.

## See also

[**PsGetCurrentProcessId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[**PsGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[**PsGetProcessId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetprocessid)