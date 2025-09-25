# KeQueryMaximumProcessorCountEx function (ntddk.h)

## Description

The **KeQueryMaximumProcessorCountEx** routine returns the maximum number of logical processors in a specified group in a multiprocessor system.

## Parameters

### `GroupNumber` [in]

Specifies a group number. If a multiprocessor system contains *n* groups, the groups are numbered from 0 to *n*-1. To obtain the maximum number of processors in the system, set this parameter to ALL_PROCESSOR_GROUPS, which is defined in the Winnt.h and Ntdef.h header files.

## Return value

**KeQueryMaximumProcessorCountEx** returns the maximum number of logical processors in the specified group or in the system, as indicated by the value of the *GroupNumber* parameter.

## Remarks

The value that is returned by **KeQueryMaximumProcessorCountEx** remains constant during runtime. This value depends on the hardware configuration of the multiprocessor system, but it can never exceed a fixed limit that is set by the Windows operating system. This limit is 32 logical processors for 32-bit versions of Windows and 64 logical processors for 64-bit versions of Windows.

In contrast, the value that is returned by the [KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex) routine can change during runtime as processors are dynamically added to the system.

A related routine, [KeQueryMaximumProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumprocessorcount), returns a maximum processor count, but this routine, unlike **KeQueryMaximumProcessorCountEx**, does not accept a group number as an input parameter. In Windows 7 and later versions of the Windows operating system, **KeQueryMaximumProcessorCount** returns the maximum number of logical processors in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. This behavior ensures that existing drivers that call **KeQueryMaximumProcessorCount** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeQueryMaximumProcessorCountEx** instead of **KeQueryMaximumProcessorCount**.

## See also

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[KeQueryMaximumProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumprocessorcount)