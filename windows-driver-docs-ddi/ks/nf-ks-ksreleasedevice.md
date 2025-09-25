# KsReleaseDevice function

## Description

The **KsReleaseDevice** function releases the device mutex and exits the critical region.

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the AVStream device for which to release synchronous control.

## Remarks

**KsReleaseDevice** is used by a client that has finished accessing the device in a synchronous manner following a previous call to [KsAcquireDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquiredevice).

For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KsAcquireDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquiredevice)