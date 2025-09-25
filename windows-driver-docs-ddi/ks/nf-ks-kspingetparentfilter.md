# KsPinGetParentFilter function

## Description

The **KsPinGetParentFilter** function returns the parent filter of *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) for which to return the parent filter.

## Return value

**KsPinGetParentFilter** returns a pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the parent filter of *Pin*.

## Remarks

**KsPinGetParentFilter** returns the filter to which *Pin* belongs. The call is an inline function call to [KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent). Note that the object hierarchy is only stable while the appropriate mutex is held, in this case the filter control mutex. See [AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview) For more information about the object hierarchy in AVStream and [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream) For more information about mutexes in the AVStream environment.

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent)