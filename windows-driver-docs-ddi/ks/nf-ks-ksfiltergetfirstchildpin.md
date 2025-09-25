# KsFilterGetFirstChildPin function

## Description

The **KsFilterGetFirstChildPin** function returns the first instantiated pin of type *PinID* on the filter specified by *Filter*.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure to query for instantiated pins.

### `PinId` [in]

The numeric ID of the pin type for which to find the first instantiated member.

## Return value

**KsFilterGetFirstChildPin** returns a pointer to the first instantiated [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure of type *PinID* on the specified filter.

## Remarks

Note that the object hierarchy is guaranteed stable only while the appropriate mutex is held, in this case the filter control mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterGetChildPinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetchildpincount)

[KsPinGetNextSiblingPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetnextsiblingpin)