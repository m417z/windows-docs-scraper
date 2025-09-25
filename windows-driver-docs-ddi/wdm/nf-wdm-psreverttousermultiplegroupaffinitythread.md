## Description

The **PsRevertToUserMultipleGroupAffinityThread** function reverts the current thread to its previous affinity as indicated by the given affinity token.

The given affinity token must have been filled in by a successful call to [**PsSetSystemMultipleGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pssetsystemmultiplegroupaffinitythread).

## Parameters

### `AffinityToken` [in]

Supplies a pointer to an affinity token.

## Remarks

## See also

[PsSetSystemMultipleGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pssetsystemmultiplegroupaffinitythread).