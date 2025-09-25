# KsPinAcquireControl function

## Description

The **KsPinAcquireControl** function acquires the control mutex for the AVStream pin specified by *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) for which to acquire the control mutex.

## Remarks

The pin control mutex is the same mutex that is used by *Pin*'s parent. This means that the mutex for *Pin* is also a filter control mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

**KsPinAcquireControl** is an inline call to [KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol) with the appropriate typecasting. Minidrivers manipulating pins should call **KsPinAcquireControl** instead of calling **KsAcquireControl** directly.

## See also

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol)

[KsPinReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleasecontrol)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)