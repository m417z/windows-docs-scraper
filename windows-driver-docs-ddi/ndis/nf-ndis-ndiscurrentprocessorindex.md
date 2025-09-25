# NdisCurrentProcessorIndex function

## Description

The
**NdisCurrentProcessorIndex** function returns the system-assigned number of the current processor that
the caller is running on.

## Return value

**NdisCurrentProcessorIndex** returns a ULONG value that represents the processor that the caller is
currently running on. The number of processors in a symmetric multiprocessor (SMP) computer is a
zero-based value.

## Remarks

NDIS drivers call the
**NdisCurrentProcessorIndex** function to obtain the system-assigned number of the current processor
that the caller is running on.

## See also

[KeGetCurrentProcessorNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumber)

[NDIS_CURRENT_PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-current-processor-number)