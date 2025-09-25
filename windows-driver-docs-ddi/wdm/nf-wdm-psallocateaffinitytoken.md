## Description

The **PsAllocateAffinityToken** function allocates a thread affinity token. After use, the token must be freed by calling [**PsFreeAffinityToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psfreeaffinitytoken).

## Parameters

### `AffinityToken` [out]

Supplies a pointer to a buffer which, on success, receives a pointer to the newly allocated affinity token.

## Return value

Returns an NTSTATUS code.

## Remarks

## See also

[PsFreeAffinityToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psfreeaffinitytoken)