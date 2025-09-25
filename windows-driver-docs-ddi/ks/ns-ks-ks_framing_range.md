# KS_FRAMING_RANGE structure

## Description

The KS_FRAMING_RANGE structure specifies a range for frame sizes for a given framing item.

## Members

### `MinFrameSize`

Specifies a minimum frame size of type ULONG.

### `MaxFrameSize`

Specifies a maximum frame size of type ULONG.

### `Stepping`

Specifies the step value that should be used to create legal values within the range defined in **MinFrameSize** and **MaxFrameSize**.

## Remarks

When specifying the **Stepping** member, ensure that the value does not exceed the difference between the **MinFrameSize** and **MaxFrameSize** members. Otherwise, unpredictable behavior may result.

## See also

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)

[KS_FRAMING_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_item)

[KS_FRAMING_RANGE_WEIGHTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_range_weighted)