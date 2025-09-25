# KeQueryGroupAffinity function (wdm.h)

## Description

The **KeQueryGroupAffinity** routine returns an affinity mask that identifies the active logical processors in a specified group in a multiprocessor system.

## Parameters

### `GroupNumber` [in]

The group number. If a multiprocessor system contains *n* groups, the groups are numbered from 0 to *n*-1. To obtain the number of active groups in the system, call the [KeQueryActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactivegroupcount) routine.

## Return value

**KeQueryGroupAffinity** returns a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value that identifies the active logical processors in the specified group. If the *GroupNumber* parameter value is not a valid group number, the routine returns zero.

## Remarks

A related routine, [KeQueryActiveProcessors](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessors), returns an affinity mask that represents a set of active processors, but this routine, unlike **KeQueryGroupAffinity**, does not accept a group number as an input parameter. In Windows 7 and later versions of the Windows operating system, **KeQueryActiveProcessors** returns an affinity mask for the active processors in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. This behavior ensures that existing drivers that call **KeQueryActiveProcessors** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeQueryGroupAffinity** instead of **KeQueryActiveProcessors**.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KeQueryActiveProcessors](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessors)