## Description

This function queries the attributes of a power limit request object.

## Parameters

### `PowerLimitRequest`

A pointer to the power limit request object returned by [PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest).

### `BufferCount`

Entries of the parameter *Buffer*.

### `Buffer`

A pre-allocated buffer to save [**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes) of each power limit types of power limit domains.

### `AttributeCount`

A pointer to save the number of attributes this platform supports. It should be the sum of power limit types of all domains.

## Return value

Returns an NTSTATUS value.

## Remarks

The policy calls this interface twice and allocates a buffer in between:

1. Call with *BufferCount = 0*, *Buffer = NULL*, the OS will update AttributeCount.

1. Allocate continuous memory for *AttributeCount* of [**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes).

1. Call with updated *BufferCount* and *Buffer*.

## See also

[PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest)

[PoDeletePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-podeletepowerlimitrequest)

[PoQueryPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitvalue)

[PoSetPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetpowerlimitvalue)

[**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes)

[**POWER_LIMIT_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ne-ntpoapi-power_limit_types)

[**POWER_LIMIT_VALUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_value)