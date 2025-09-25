# NtSetInformationThread function

## Description

The **NtSetInformationThread** routine sets the priority of a thread.

## Parameters

### `ThreadHandle` [in]

Handle to the thread object. To create a new thread and get a handle to it, call [**PsCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread). To specify the current thread, use the [**ZwCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/kernel/zwcurrentthread) macro.

### `ThreadInformationClass` [in]

One of the system-defined values in the THREADINFOCLASS enumeration (see ntddk.h), **ThreadPriority**, **ThreadBasePriority**, **ThreadPagePriority**, or **ThreadPowerThrottlingState**.

### `ThreadInformation` [in]

Pointer to a variable that specifies the information to set.

If **ThreadInformationClass** is **ThreadPriority**, this value must be > LOW_PRIORITY and <= HIGH_PRIORITY.

If **ThreadInformationClass** is **ThreadBasePriority**, this value must fall within the system's valid base-priority range and the original priority class for the given thread. That is, if a thread's priority class is variable, that thread's base priority cannot be reset to a real-time priority value, and vice versa.

If **ThreadInformationClass** is **ThreadPagePriority**, this value is a pointer to a **PAGE_PRIORITY_INFORMATION** structure, see ntddk.h. The **PagePriority** member value must be one of these values.

If **ThreadInformationClass** is **ThreadPowerThrottlingState**, this value is a pointer to a [**POWER_THROTTLING_THREAD_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_power_throttling_thread_state) structure, see ntddk.h. The **PagePriority** member value must be one of these values.

| Value | Meaning |
| ----- | ------- |
| MEMORY_PRIORITY_VERY_LOW (1) | Very low memory priority. |
| MEMORY_PRIORITY_LOW (2) | Low memory priority. |
| MEMORY_PRIORITY_MEDIUM (3) | Medium memory priority. |
| MEMORY_PRIORITY_BELOW_NORMAL (4) | Below normal memory priority. |
| MEMORY_PRIORITY_NORMAL (5) | Normal memory priority. This is the default priority for all threads and processes on the system. |

### `ThreadInformationLength` [in]

The size, in bytes, of **ThreadInformation**.

## Return value

**NtSetInformationThread** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure. Possible error codes include STATUS_INFO_LENGTH_MISMATCH or STATUS_INVALID_PARAMETER.

## Remarks

**NtSetInformationThread** can be called by higher-level drivers to set the priority of a thread for which they have a handle.

The caller must have THREAD_SET_INFORMATION access rights for the given thread in order to call this routine.

Usually, device and intermediate drivers that set up driver-created threads call [**KeSetBasePriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread) or [**KeSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread) from their driver-created threads, rather than calling **NtSetInformationThread**. However, a driver can call **NtSetInformationThread** to raise the priority of a driver-created thread before that thread runs.

Kernel mode drivers can call the **NtSetInformationThread** function with **ThreadPagePriority** to specify a thread's page priority.

To help improve system performance, drivers should use the function with **ThreadPagePriority** to lower the page priority of threads that perform background operations or access files and data that are not expected to be accessed again soon. For example, an anti-malware application might lower the priority of threads involved in scanning files.

> [!NOTE]
> If the call to this function occurs in kernel mode, you should use the name [**ZwSetInformationThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwsetinformationthread) instead of **NtSetInformationThread**.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)..

## See also

[**KeSetBasePriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread)

[**KeSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread)

[**PsCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).