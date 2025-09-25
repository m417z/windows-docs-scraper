# KsFilterAttemptProcessing function

## Description

The **KsFilterAttemptProcessing** function attempts to initiate processing on *Filter*.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the AVStream filter object on which to attempt processing.

### `Asynchronous` [in]

This parameter contains an indication as to whether the processing dispatch should occur asynchronously or not (should it occur). An asynchronous dispatch is guaranteed if this is **TRUE**; however, synchronous processing dispatches are governed by conditions described below.

## Remarks

If the minidriver calls **KsFilterAttemptProcessing** when all of the conditions required to process data are met, a processing dispatch occurs. For more information about the process callback, see [KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch). In order for the attempt to result in an actual dispatch, the filter's process control gate must be in an open state. Unlike pin-centric processing, filter-centric processing has many conditions that affect the process control gate. For more information about these requirements, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) and [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing).

If the process control gate is open, a processing dispatch occurs, either synchronously or asynchronously. If the caller specifies **TRUE** in the *Asynchronous* parameter, the processing dispatch always occurs asynchronously in a work item. However, if the caller requests a synchronous processing dispatch, the dispatch occurs synchronously only if the system is currently at an IRQL at which the minidriver can handle processing. If the system is at PASSIVE_LEVEL, the dispatch is guaranteed to happen synchronously. Conversely, if the system is at DISPATCH_LEVEL, the dispatch happens synchronously only if KSFILTER_FLAG_DISPATCH_LEVEL_PROCESSING is specified on the filter. Otherwise, a work item is queued to perform processing.

Note that this is only an attempt at processing; calling this function does not guarantee that processing will commence. Processing occurs only if the process control gate is "open." For more information, see [Restarting Processing in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/restarting-processing-in-avstream) and [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

## See also

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateCaptureThreshold](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgatecapturethreshold)

[KsPinAttemptProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattemptprocessing)