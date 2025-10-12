## Description

 The **POWER_LIMIT_ATTRIBUTES** structure describes the attributes of each power limit type.

## Members

### `Type`

Indicates which [**POWER_LIMIT_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ne-ntpoapi-power_limit_types) this attribute is associated with.

### `DomainId`

Indicates which domain this attribute is associated with.

### `MaxValue`

The maximum supported value (inclusive), unit is mW for power, mA for current.

### `MinValue`

The minimum supported value (inclusive), unit is mW for power, mA for current.

### `MinTimeParameter`

The minimum supported time parameter (inclusive), unit is microsecond.

### `MaxTimeParameter`

The maximum supported time parameter (inclusive), unit is microsecond.

### `DefaultACValue`

The default AC value, unit is mW for power, mA for current, microsecond for time parameters.

### `DefaultDCValue`

The default DC value, unit is mW for power, mA for current, microsecond for time parameters.

### `Flags`

Defines the Flags union.

### `Flags.SupportTimeParameter`

Set to 1 if this limit supports time parameter.

### `Flags.Reserved`

Reserved

### `Flags.AsUlong`

Defines the AsULong member of the Flags union.

## Remarks

Each instance of **POWER_LIMIT_ATTRIBUTES** is associated with one domain and one type. For example, if one power limit device has 2 domains: domain 0 supports PowerLimitContinuous, domain 1 supports PowerLimitContinuous and PowerLimitPreemptive.

## See also

[PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest)

[PoDeletePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-podeletepowerlimitrequest)

[PoQueryPowerLimitAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitattributes)

[PoQueryPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitvalue)

[PoSetPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetpowerlimitvalue)

[**POWER_LIMIT_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ne-ntpoapi-power_limit_types)

[**POWER_LIMIT_VALUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_value)