## Description

The **PsQuerySystemAvailableCpusCount** function queries the count of CPUs that are available to the system process.

## Parameters

### `AvailableCpuCount` [out]

Pointer to a buffer that will receive the count of available CPUs to the system process.

### `SequenceNumber` [out]

Pointer to a buffer that will receive the current sequence number for the available CPUs to the system process.

## Return value

**PsQuerySystemAvailableCpusCount** returns an NTSTATUS value. Possible return values include:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The query was completed successfully. |
| **STATUS_INVALID_PARAMETER** | Any of the required parameters is NULL. |

## Remarks

This routine can be called at IRQL from PASSIVE_LEVEL to DISPATCH_LEVEL.

This function provides a simpler alternative to [**PsQuerySystemAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpus) when only the count of available CPUs is needed, rather than the detailed affinity information.

The sequence number allows callers to track changes in CPU availability and can be used with [**PsQuerySystemAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpus) for optimized queries.

This function queries CPU availability for the system process, which typically represents all available CPUs in the system.

## See also

[**PsQuerySystemAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpus)

[**PsQueryProcessAvailableCpusCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpuscount)