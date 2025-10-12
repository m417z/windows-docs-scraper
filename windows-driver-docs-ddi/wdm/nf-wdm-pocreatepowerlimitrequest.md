## Description

This function creates a power limit request object.

## Parameters

### `PowerLimitRequest`

A pointer to receive the power limit request object.

### `TargetDeviceObject`

Supplies the device object of the device to apply power limits.

### `PolicyDeviceObject`

Supplies the device object of the device creating power limit requests.

### `Context`

 A pointer to a [**COUNTED_REASON_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_counted_reason_context) structure that describes why the caller is creating the power limit request object.

## Return value

Returns an NTSTATUS value.

## See also

[PoDeletePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-podeletepowerlimitrequest)

[PoQueryPowerLimitAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitattributes)

[PoQueryPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitvalue)

[PoSetPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetpowerlimitvalue)

[**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes)

[**POWER_LIMIT_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ne-ntpoapi-power_limit_types)

[**POWER_LIMIT_VALUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_value)