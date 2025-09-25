# KsFilterCreatePinFactory function

## Description

The **KsFilterCreatePinFactory** function creates a new pin factory on the specified filter.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to create a new pin factory.

### `PinDescriptor` [in]

A pointer to a [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) structure that describes the pins this factory will create.

### `PinID` [out]

A pointer to the location containing the ID of the new factory.

## Return value

**KsFilterCreatePinFactory** returns the success or failure of the attempt to create the pin factory. Failure may occur due to invalid parameters or low memory.

## Remarks

Note that the filter control mutex must be held before calling this function. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsFilterCreateNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltercreatenode)