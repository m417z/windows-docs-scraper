# KeQueryActiveGroupCount function (ntddk.h)

## Description

The **KeQueryActiveGroupCount** routine returns the number of active processor groups in a multiprocessor system.

## Return value

**KeQueryActiveGroupCount** returns a count of the active groups.

## Remarks

A processor group is active if it contains one or more active logical processors.

An active logical processor is a logical processor that Windows has started up and added to a multiprocessor system. The term *active processor* applies to a processor that is available to perform processing work, regardless of whether the processor is currently performing processing work or is idle. In some systems, the number of active processors might remain unchanged from system startup to shutdown. In other systems, Windows might dynamically add active processors while the system is running. Windows never removes active processors from a system.

Thus, the number of active processors in a multiprocessor system can increase between system startup and shutdown, but this number never decreases. Similarly, the number of active groups in the system can increase if a processor is dynamically added to an inactive group while the system is running. The number of active groups never decreases.

In contrast, the value that is returned by [KeQueryMaximumGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumgroupcount) remains constant during runtime. This value is the maximum number of groups that the system can have.

Call the [KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex) routine to determine the number of active logical processors in a particular group.

Windows 7 is the first version of Windows to support processor groups. In Windows 7, only 64-bit versions of Windows support multiple groups; 32-bit versions of Windows support only one group. A multiprocessor system that is running a 32-bit version of Windows can contain no more than 32 processors.

## See also

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[KeQueryMaximumGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumgroupcount)