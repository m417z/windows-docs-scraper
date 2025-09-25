# KsReleaseControl function

## Description

The **KsReleaseControl** function releases the control mutex for *Object*.

## Parameters

### `Object` [in]

The object for which to release the control mutex.

## Remarks

*Object* should be either a filter or a pin cast to PVOID.

Minidrivers typically do not call **KsReleaseControl** directly, but instead call [KsFilterReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterreleasecontrol) or [KsPinReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleasecontrol). These versions automatically provide the necessary typecasting to PVOID.

For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol)

[KsFilterAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquirecontrol)

[KsFilterReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterreleasecontrol)

[KsPinAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquirecontrol)

[KsPinReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleasecontrol)