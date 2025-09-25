# SERVICE_TRIGGER_INFO structure

## Description

Contains trigger event information for a service. This structure is used by the [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) and [QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a) functions.

## Members

### `cTriggers`

The number of triggers in the array of [SERVICE_TRIGGER](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger) structures pointed to by the **pTriggers** member.

If this member is 0 in a **SERVICE_TRIGGER_INFO** structure passed to [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a), all previously configured triggers are removed from the service. If the service has no triggers configured, **ChangeServiceConfig2** fails with ERROR_INVALID_PARAMETER.

### `cTriggers.range`

### `cTriggers.range.0`

### `cTriggers.range.64`

### `pTriggers`

A pointer to an array of [SERVICE_TRIGGER](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger) structures that specify the trigger events for the service. If the **cTriggers** member is 0, this member is not used.

### `pTriggers.size_is`

### `pTriggers.size_is.cTriggers`

### `pReserved`

This member is reserved and must be NULL.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[SERVICE_TRIGGER](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger)

[Service Trigger Events](https://learn.microsoft.com/windows/desktop/Services/service-trigger-events)