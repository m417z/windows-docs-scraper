# KeGetCurrentThread function

## Description

The **KeGetCurrentThread** routine identifies the current thread.

## Return value

**KeGetCurrentThread** returns a pointer to an opaque thread object.

## Remarks

This routine is identical to [PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread).

A caller of **KeGetCurrentThread** can use the returned pointer as an input parameter to [KeQueryPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryprioritythread), [KeSetBasePriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread), or [KeSetPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread). However, the memory containing the thread object is opaque; that is, it is reserved for exclusive use by the operating system.

## See also

[KeQueryPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryprioritythread)

[KeSetBasePriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread)

[KeSetPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)