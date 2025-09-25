# KsFilterAcquireProcessingMutex function

## Description

The **KsFilterAcquireProcessingMutex** function acquires the processing mutex for a specified AVStream filter.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the AVStream filter for which to acquire the processing mutex.

## Remarks

AVStream holds the processing control mutex upon return from this routine. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

A minidriver that must suspend processing for a long period of time should not use this mechanism. Instead, it should manipulate the processing control gate directly by using the **KSGATE***Xxx* functions.

## See also

[KsFilterAttemptProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterattemptprocessing)

**KsFilterReleaseProcessingMutex**

[KsPinAcquireProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquireprocessingmutex)

[KsPinGetAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetandgate)

[KsPinReleaseProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleaseprocessingmutex)