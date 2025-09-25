# KsFilterGetChildPinCount function

## Description

The **KsFilterGetChildPinCount**functionreturns the number of pins of a given type that are currently instantiated on a given filter.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to find the number of instantiated pins of type *PinID*.

### `PinId` [in]

The pin type for which to find the number of instantiated pins. *PinID* is an index into the array of pin descriptors for the filter to which the pin belongs.

## Return value

**KsFilterGetChildPinCount** returns the number of pins of type *PinID* that are currently instantiated on *Filter*. If no such pins exist or if *PinID* is out of range, zero is returned.

## Remarks

The count returned by this call is guaranteed to be correct only if the function is called while the filter control mutex is held. The count remains correct after the call as long as this mutex continues to be held. As soon as the mutex is released, other pins can be added or removed, thereby altering the actual pin count.

For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterGetFirstChildPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetfirstchildpin)

[KsPinGetNextSiblingPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetnextsiblingpin)