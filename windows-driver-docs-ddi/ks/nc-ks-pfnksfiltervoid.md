# PFNKSFILTERVOID callback function

## Description

An AVStream minidriver's *AVStrMiniFilterReset* routine is called when AVStream receives an IOCTL_KS_RESET_STATE to return the filter to the state it was in at *Acquire*-time. This routine is also called when a queue associated with a pin on the filter is flushed. *This routine will only be called for a filter-centric filter*.

## Parameters

### `Filter` [in]

Pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) to return to its previous state.

## Return value

AVStream does not currently use the return value.

## Remarks

For more information, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

Note that it is not the filter in question, but rather a pin on this filter that actually receives the reset IOCTL.

The minidriver specifies this routine's address in the **Reset** member of its [KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure.

The filter control mutex may be held during this function. See [Filter Control Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream).

This routine is optional.

## See also

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)