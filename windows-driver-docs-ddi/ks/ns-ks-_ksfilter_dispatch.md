# _KSFILTER_DISPATCH structure

## Description

The KSFILTER_DISPATCH structure describes the client callbacks that are made to notify the client of certain events on a given filter type.

## Members

### `Create`

Optional. A pointer to a minidriver-supplied [AVStrMiniFilterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfilterirp) callback routine.

### `Close`

Optional. A pointer to a minidriver-supplied [AVStrMiniFilterClose](https://learn.microsoft.com/previous-versions/ff556307(v=vs.85)) callback routine.

### `Process`

Optional. A pointer to a minidriver-supplied [AVStrMiniFilterProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfilterprocess) callback routine.

### `Reset`

Optional. A pointer to a minidriver-supplied [AVStrMiniFilterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfiltervoid) callback routine.

## Remarks

Any of the callback pointers may be **NULL**, indicating that the driver does not wish to receive notification of a given event.

Also see [Restarting Processing in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/restarting-processing-in-avstream) and

[Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## See also

[KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin)

[KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry)

[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)