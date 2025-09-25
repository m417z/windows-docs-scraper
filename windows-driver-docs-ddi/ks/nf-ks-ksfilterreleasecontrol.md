# KsFilterReleaseControl function

## Description

The **KsFilterReleaseControl** function releases the control mutex for the AVStream filter specified by *Filter*.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the AVStream filter for which to release the control mutex.

## Remarks

This function is an inline call to [KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol) with the appropriate typecasting. When manipulating a filter, minidrivers should call this function instead of calling **KsReleaseControl** directly.

For a description of the filter control mutex, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsFilterAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquirecontrol)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)