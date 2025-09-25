## Description

The **PsQueryProcessAvailableCpusCount** function queries the count of CPUs that are available for a given process to run on.

## Parameters

### `Process` [in]

Pointer to a process (PEPROCESS).

### `AvailableCpuCount` [out]

Pointer to a buffer that will receive the count of available CPUs to the given process.

### `SequenceNumber` [out]

Pointer to a buffer that will receive the current sequence number for the available CPUs to the given process.

## Return value

**PsQueryProcessAvailableCpusCount** returns an NTSTATUS value. Possible return values include:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The query was completed successfully. |
| **STATUS_INVALID_PARAMETER** | Any of the required parameters is NULL. |

## Remarks

This routine can be called at IRQL from PASSIVE_LEVEL to DISPATCH_LEVEL.

This function provides a simpler alternative to [**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus) when only the count of available CPUs is needed, rather than the detailed affinity information.

The sequence number allows callers to track changes in CPU availability and can be used with [**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus) for optimized queries.

## See also

[**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus)

[**PsQuerySystemAvailableCpusCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpuscount)