# IServiceGroup::RequestDelayedService

## Description

The `RequestDelayedService` method requests service after the specified delay.

## Parameters

### `ullDelay` [in]

Specifies the absolute or relative time at which the timer is to expire. If the value of *ulDelay* is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. The expiration time is expressed in system time units (100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

## Remarks

Before calling `RequestDelayedService` to request a timer delay, initialize the timer by calling [IServiceGroup::SupportDelayedService](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iservicegroup-supportdelayedservice).

## See also

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceGroup::SupportDelayedService](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iservicegroup-supportdelayedservice)