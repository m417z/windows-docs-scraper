# KsAcquireControl function

## Description

The **KsAcquireControl** function acquires the filter control mutex for *Object*.

## Parameters

### `Object` [in]

A pointer to the object for which to acquire the filter control mutex. This should be a pointer to either a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) or a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin), cast to PVOID.

## Remarks

Minidrivers typically do not call this function directly, but instead call either [KsFilterAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquirecontrol) or [KsPinAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquirecontrol). These functions provide the necessary typecasting to PVOID automatically.

For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquirecontrol)

[KsPinAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquirecontrol)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)