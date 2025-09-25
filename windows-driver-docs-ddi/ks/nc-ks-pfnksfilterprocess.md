## Description

An AVStream minidriver's *AVStrMiniFilterProcess* routine is called when the filter is meant to process frames. It is used to perform [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## Parameters

### `Filter` [in]

Pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure that must process frames.

### `Index`

Pointer to an array of [KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry) structures that AVStream orders by pin ID.

## Return value

Return STATUS_SUCCESS to continue processing. Return STATUS_PENDING to stop processing until the next triggering event. The minidriver may return an error code, but this will be treated as described for STATUS_PENDING.

## Remarks

The minidriver specifies this routine's address in the **Process** member of its [KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure.

The routine is called at either IRQL = DISPATCH_LEVEL or PASSIVE_LEVEL depending on the preference expressed in the filter descriptor. Filter descriptors that specify KSFILTER_FLAG_DISPATCH_LEVEL_PROCESSING may have their process callback at DISPATCH_LEVEL; filter descriptors that do not specify this flag will have their process callback at PASSIVE_LEVEL.

For more information, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) and [Restarting Processing in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/restarting-processing-in-avstream).

This routine is optional.

## See also

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry)