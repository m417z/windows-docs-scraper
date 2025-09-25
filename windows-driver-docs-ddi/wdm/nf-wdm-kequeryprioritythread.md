# KeQueryPriorityThread function

## Description

The **KeQueryPriorityThread** routine returns the current priority of a particular thread.

## Parameters

### `Thread` [in]

Pointer to a dispatcher object of type KTHREAD.

## Return value

**KeQueryPriorityThread** returns the current priority of the specified thread.

## Remarks

Thread priorities range from 0 to 31, where 0 is the lowest priority and 31 is the highest.

## See also

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[KeSetBasePriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread)

[KeSetPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)