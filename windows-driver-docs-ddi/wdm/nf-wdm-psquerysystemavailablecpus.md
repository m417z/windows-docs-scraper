## Description

The **PsQuerySystemAvailableCpus** function queries the set of CPUs that are available to the system process.

## Parameters

### `Affinity` [in, out]

Pointer to an extended affinity object (PKAFFINITY_EX) that will receive the set of available CPUs for the system process.

### `ObservedSequenceNumber` [in, optional]

Optional pointer to the most recent sequence number observed by the caller through a previous call to this routine. If this sequence number matches the current sequence number, the routine returns STATUS_NO_WORK_DONE and does not write to the affinity buffer.

### `SequenceNumber` [out]

Pointer to a buffer which will receive the current sequence number for the available CPUs to the system process.

## Return value

**PsQuerySystemAvailableCpus** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The query was completed successfully. |
| **STATUS_INVALID_PARAMETER** | Any of the required buffers is NULL. |
| **STATUS_NO_WORK_DONE** | The given sequence number matches the current sequence number and no query was performed. |
| **STATUS_BUFFER_TOO_SMALL** | The given affinity buffer is too small. |

## Remarks

This routine can be called at IRQL from PASSIVE_LEVEL to DISPATCH_LEVEL.

The affinity buffer must be large enough to accommodate the active processor group count. Use [**KeQueryActiveGroupCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactivegroupcount) to determine the required size.

The sequence number allows callers to optimize repeated queries by checking if the CPU availability has changed since the last call.

This function queries CPU availability for the system process, which typically represents all available CPUs in the system.

## See also

[**PsQuerySystemAvailableCpusCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpuscount)

[**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus)

[**KeQueryActiveGroupCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactivegroupcount)