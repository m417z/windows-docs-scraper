# KsFilterReleaseProcessingMutex function

## Description

The **KsFilterReleaseProcessingMutex** function releases the processing mutex for the AVStream filter specified by *Filter*.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the AVStream filter for which to release the processing mutex.

## Remarks

For more AVStream-specific information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream) and [Processing Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/processing-mutex-in-avstream).

## See also

[KsFilterAcquireProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquireprocessingmutex)