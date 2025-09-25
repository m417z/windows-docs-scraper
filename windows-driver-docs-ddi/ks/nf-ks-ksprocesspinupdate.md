# KsProcessPinUpdate function

## Description

The **KsProcessPinUpdate** function is called from within a filter-centric filter's [AVStrMiniFilterProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfilterprocess) dispatch to update a process pin.

## Parameters

### `ProcessPin` [in]

A pointer to a [KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin) structure that represents the process pin to update.

## Return value

**KsProcessPinUpdate** returns **TRUE** if *ProcessPin*'s conditions for processing are met; otherwise, it returns **FALSE**. (These conditions are set in the pin descriptor within the **Pin** member of *ProcessPin*.) If the minidriver's dispatch calls this routine while the filter is in the STOP state, **KsProcessPinUpdate** returns **FALSE** since no pipe exists.

## Remarks

For more information, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## See also

[KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin)

[KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry)