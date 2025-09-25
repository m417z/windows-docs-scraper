# KsPinReleaseControl function

## Description

The **KsPinReleaseControl** function releases the control mutex for the AVStream pin specified by *Pin*.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the pin for which to release the control mutex.

## Remarks

The pin control mutex is the same mutex that is used by *Pin*'s parent. In other words, the pin control mutex *is* the filter control mutex of *Pin*'s parent. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

Note that this function is an inline call to [KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol). Minidrivers manipulating a pin should call this function instead of calling **KsReleaseControl** directly.

## See also

[KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol)

[KsPinAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquirecontrol)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)