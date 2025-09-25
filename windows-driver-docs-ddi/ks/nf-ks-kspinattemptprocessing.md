## Description

The KsPinAttemptProcessing function is used to resume processing on a specific pin on a pin-centric filter. It attempts to initiate processing on *Pin* by sending a processing dispatch call to *Pin*'s processing object.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that represents the AVStream pin object on which to attempt processing.

> [!WARNING]
> This parameter is mandatory. If you call KsPinAttemptProcessing with a *Pin* value of **NULL**, system instability may result.

### `Asynchronous` [in]

This parameter indicates the minidriver's preference whether the processing should occur synchronously or asynchronously. If **TRUE**, processing is always asynchronous. However, synchronous processing only happens under certain circumstances. For more information, see the Remarks section below.

## Remarks

A minidriver may need to call KsPinAttemptProcessing to resume processing in various situations. For example, if the client has shut off the processing control gate with [KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff), call this function when ready to attempt processing. Note that this only causes a processing dispatch if the process control gate is in the open state. Another situation involves the minidriver having previously returning STATUS_PENDING to a processing dispatch. For more details, see [Restarting Processing in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/restarting-processing-in-avstream) and [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

The processing dispatch occurs either synchronously or asynchronously, and *only* if the processing control gate is open. The *Asynchronous* flag specifies the minidriver's preference. If the minidriver requests an asynchronous process dispatch, the dispatch is always asynchronous. However, even if the caller sets *Asynchronous* to **FALSE**, a synchronous dispatch only occurs if the system is currently running at an IRQL less than the maximum processing IRQL. In other words, if the minidriver does not specify dispatch level processing and the call is made at IRQL = DISPATCH_LEVEL, then the call occurs in an asynchronous work item at PASSIVE_LEVEL regardless of the value of *Asynchronous*. For more information, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) and [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing).

## See also

[**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[KsFilterAttemptProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterattemptprocessing)

[KsGateCaptureThreshold](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgatecapturethreshold)