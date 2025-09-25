# IoInitializePriorityInfo function

## Description

The **IoInitializePriorityInfo** routine initializes a structure of type [IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info).

## Parameters

### `PriorityInfo` [in]

Pointer to a structure, of type IO_PRIORITY_INFO, to be initialized. This parameter is required and cannot be **NULL**.

## Remarks

The **IoInitializePriorityInfo** routine is used to initialize the IO_PRIORITY_INFO structure that is utilized by the [FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo) routine.

## See also

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info)