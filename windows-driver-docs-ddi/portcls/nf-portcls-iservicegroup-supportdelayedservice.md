# IServiceGroup::SupportDelayedService

## Description

The `SupportDelayedService` method indicates that the service group should prepare to support delayed service.

## Remarks

The `SupportDelayedService` method initializes the notification timer that is used for delayed service. Call this method once before making any calls to [IServiceGroup::RequestDelayedService](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iservicegroup-requestdelayedservice).

## See also

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceGroup::RequestDelayedService](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iservicegroup-requestdelayedservice)