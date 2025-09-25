# SERVICE_FAILURE_ACTIONS_FLAG structure

## Description

Contains the failure actions flag setting of a service. This setting determines when failure actions are to be executed.

## Members

### `fFailureActionsOnNonCrashFailures`

If this member is **TRUE** and the service has configured failure actions, the failure actions are queued if the service process terminates without reporting a status of SERVICE_STOPPED or if it enters the SERVICE_STOPPED state but the **dwWin32ExitCode** member of the [SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status) structure is not ERROR_SUCCESS (0).

If this member is **FALSE** and the service has configured failure actions, the failure actions are queued only if the service terminates without reporting a status of SERVICE_STOPPED.

This setting is ignored unless the service has configured failure actions. For information on configuring failure actions, see [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a).

## Remarks

The change takes effect the next time the system is started.

It can be useful to set this flag if your service has common failure paths where is it possible that the service could recover.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsa)