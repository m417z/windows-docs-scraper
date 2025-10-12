## Description

The **PsSetSystemMultipleGroupAffinityThread** function sets the multi-group system affinity of the current thread.

## Parameters

### `GroupAffinities` [in]

Supplies a pointer to an array of group affinity structures, which describe the new system affinity of the current thread.

### `GroupCount` [in]

Supplies the number of elements in the group affinity array.

### `AffinityToken` [in, out]

Supplies a pointer to an affinity token structure which must be returned by [**PsAllocateAffinityToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psallocateaffinitytoken). On output it receives an opaque affinity token that must be passed to [**PsRevertToUserMultipleGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psreverttousermultiplegroupaffinitythread) to revert the thread to its previous affinity.

## Return value

Returns an NTSTATUS code.

## Remarks

## See also

[PsAllocateAffinityToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psallocateaffinitytoken)

[PsRevertToUserMultipleGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psreverttousermultiplegroupaffinitythread)