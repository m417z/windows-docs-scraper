# KsPinAcquireProcessingMutex function

## Description

The **KsPinAcquireProcessingMutex** function acquires the processing mutex for the AVStream pin specified by *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to acquire the processing mutex.

## Remarks

For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsPinAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquirecontrol)

[KsPinReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleasecontrol)

[KsPinReleaseProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleaseprocessingmutex)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)