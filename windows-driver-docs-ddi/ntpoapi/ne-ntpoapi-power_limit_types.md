## Description

Enumerates power limit types that describe a throttled object (power or battery discharge current) and how long the throttled object can last.

## Constants

### `PowerLimitContinuous`

The platform could sustain infinitely if the average power is under this limit.

### `PowerLimitBurst`

The platform could typically sustain at seconds level if the average power is higher than **PowerLimitContinuous** but lower than this limit.

### `PowerLimitRapid`

The platform starts associated algorithm to throttle the domain reactively once the power peaks above this limit.

### `PowerLimitPreemptive`

A limit that will not be exceeded, the platform will be preemptively throttled to prevent spikes above this limit.

### `PowerLimitPreemptiveOffset`

The sum of peak power of specified devices, which is used to adjust **PowerLimitPreemptive** at runtime.

## See also

[PoCreatePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pocreatepowerlimitrequest)

[PoDeletePowerLimitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-podeletepowerlimitrequest)

[PoQueryPowerLimitAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitattributes)

[PoQueryPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poquerypowerlimitattributes)

[PoSetPowerLimitValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetpowerlimitvalue)

[**POWER_LIMIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_attributes)

[**POWER_LIMIT_VALUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntpoapi/ns-ntpoapi-power_limit_value)