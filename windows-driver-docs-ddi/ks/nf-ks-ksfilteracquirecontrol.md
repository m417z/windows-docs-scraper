# KsFilterAcquireControl function

## Description

The **KsFilterAcquireControl** function acquires the filter control mutex for the AVStream filter specified by *Filter*.

## Parameters

### `Filter` [in]

The [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) for which to acquire the control mutex.

## Remarks

This function is an inline call to [KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol) with the appropriate typecasting. Minidrivers that manipulate the filter control mutex should call this function instead of calling **KsAcquireControl** directly. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol)

[KsFilterReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterreleasecontrol)