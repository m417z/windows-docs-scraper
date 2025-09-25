## Description

This function queries the limit values of a power limit request object.

## Parameters

### `PowerLimitRequest`

A pointer to the power limit request object returned by [PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest).

### `ValueCount`

Supplies the number of limit values to query.

### `Values`

Supplies a pointer to the buffer that contains target limits and stores the readout.

## Return value

Returns an NTSTATUS value.

## See also

[PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest)

[PoDeletePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-podeletepowerlimitrequest)

[PoQueryPowerLimitAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitattributes)

[PoSetPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetpowerlimitvalue)

[**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes)

[**POWER_LIMIT_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ne-ntpoapi-power_limit_types)

[**POWER_LIMIT_VALUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_value)