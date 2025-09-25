# KeQueryActiveProcessorCount function (ntddk.h)

## Description

The **KeQueryActiveProcessorCount** routine returns the number of currently active processors.

## Parameters

### `ActiveProcessors` [out, optional]

A pointer to a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed variable into which the routine writes a bitmask that represents the set of currently active processors. In a hot-add environment, this mask may change during runtime. This parameter is optional and can be specified as **NULL** if the caller does not require the mask of active processors.

## Return value

**KeQueryActiveProcessorCount** returns the number of currently active processors.

## Remarks

A device driver calls the **KeQueryActiveProcessorCount** routine to retrieve the number of currently active processors. Device drivers that are built for Windows Vista and later versions of the Windows operating system should not use the **KeNumberProcessors** kernel variable for this purpose.

Callers cannot assume that the **KeQueryActiveProcessorCount** routine maps processors to bits in the returned [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value consecutively, or that the routine will return the same bitmask each time it is called.

Callers must also be aware that the value returned by **KeQueryActiveProcessorCount** can change at runtime on versions of Windows that support hot-add CPU functionality.

If necessary, register for notification of changes to the number of processors by calling the [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) routine.

To query just the affinity mask without getting the number of active processors, use [KeQueryActiveProcessors](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessors).

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex) routine, which specifies a processor group, instead of **KeQueryActiveProcessorCount**, which does not. However, the implementation of **KeQueryActiveProcessorCount** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, **KeQueryActiveProcessorCount** returns the number of active logical processors in group 0, and writes an affinity mask to **ActiveProcessors* that specifies the set of active logical processors in group 0.

## See also

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[KeQueryActiveProcessors](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessors)

[KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback)