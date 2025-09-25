# KsPinReleaseProcessingMutex function

## Description

The **KsPinReleaseProcessingMutex** function releases the processing mutex for the AVStream pin specified by *Pin*.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the AVStream pin object for which to acquire the processing mutex.

## Remarks

Minidrivers that must suspend processing for a long time should not use this mutex to do so. Instead, directly manipulate the processing control gate using the **KSGATE***Xxx* functions. See links to these functions in [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsPinAcquireProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquireprocessingmutex)