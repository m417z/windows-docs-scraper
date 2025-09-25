# KeQueryActiveProcessorCountEx function (wdm.h)

## Description

The **KeQueryActiveProcessorCountEx** routine returns the number of active logical processors in a specified group in a multiprocessor system or in the entire system.

## Parameters

### `GroupNumber` [in]

The group number. If a multiprocessor system contains *n* groups, valid group numbers range from 0 to *n*-1. To count all active processors in all groups in the system, set this parameter to ALL_PROCESSOR_GROUPS, which is defined in header files Winnt.h and Ntdef.h.

## Return value

**KeQueryActiveProcessorCountEx** returns the number of active logical processors in the group. If *GroupNumber* is not a valid group number and is not ALL_PROCESSOR_GROUPS, it returns zero.

## Remarks

An active logical processor is a logical processor that Windows has started up and added to a multiprocessor system. The term active processor applies to a processor that is available to perform processing work, regardless of whether the processor is currently performing processing work or is idle. In some systems, the number of active processors might remain unchanged from system startup to shutdown. In other systems, Windows might dynamically add active processors while the system is running. Windows never removes active processors from a system. Thus, the number of active processors in a multiprocessor system can increase between system startup and shutdown, but this number never decreases.

A related routine, [KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount), returns an active processor count, but this routine, unlike **KeQueryActiveProcessorCountEx**, does not accept a group number as an input parameter. In Windows 7 and later versions of the Windows operating system, **KeQueryActiveProcessorCount** returns the active processor count in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. This behavior ensures that existing drivers that call **KeQueryActiveProcessorCount** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeQueryActiveProcessorCountEx** instead of **KeQueryActiveProcessorCount**.

For a code example that uses **KeQueryActiveProcessorCountEx**, see [KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex).

## See also

[KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex)

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)